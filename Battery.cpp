#include "Battery.h"

#include "GlobalDeclarations.h"

#include <cstdio>
#include <ctime>

namespace Simulator{
void Battery::SetValues(Resistance ROne,Resistance RTwo,Resistance RThree,
						Resistance RLoad,Voltage COne,Voltage CTwo,Voltage CThree,SimulationSpeed Speed)
{
	ResistorOne.SetResistance(ROne);
	ResistorTwo.SetResistance(RTwo);
	ResistorThree.SetResistance(RThree);
	ResistorLoad.SetResistance(RLoad);
	CellOne.SetPotentialVoltage(COne);
	CellTwo.SetPotentialVoltage(CTwo);
	CellThree.SetPotentialVoltage(CThree);
	Tempo=Speed;
	
}
void Battery::GetVoltages(Voltage & COne,Voltage & CTwo,Voltage & CThree)
{
	COne=CellOne.GetPotential();
	CTwo=CellTwo.GetPotential();
	CThree=CellThree.GetPotential();
}
void Battery::GetSwitchStates(CircuitElement::SwitchState & SOne,CircuitElement::SwitchState &STwo,
					 CircuitElement::SwitchState & SThree)
{
	SOne=SwitchOne.GetSwitch();
	STwo=SwitchTwo.GetSwitch();
	SThree=SwitchThree.GetSwitch();
}
void Battery::RunSim(void)
{
	/*Flow for Every Second*/
	//GetindividualCellVoltages
	//Deduce Which Switches to Make/Break
	//Run For A Second
	//Compute Individual Cell Currents Drawn
	//Compute Energy Drawn
	//Update Voltages,And Capacity
	//Update GUI
	/*Flow Ends Here*/
	time_t TimeValue = time(0),TimeValueNew = time(0) ;   // get time now
	struct tm * CurrentLocalTime = localtime( & TimeValue ),
		* CurrentLocalTimeNew=localtime( & TimeValue );
	struct SwitchHolder SwitchArray[3]={SwitchOne,SwitchTwo,SwitchThree};
	while(1)
	{
	struct CellHolder CellSorter[3]={{CellOne,1,0},{CellTwo,2,0},{CellThree,3,0}};
	bool AllCellsDischarged=true;
	for(std::uint8_t i=0;i<3;i++)
	{
		if(CellSorter[i].Cell.GetBatteryCapacity()>50)
		{
			AllCellsDischarged=false;	
		}
	}
	if(AllCellsDischarged)break;
	 TimeValueNew = time(0);
	 if(TimeValueNew != TimeValue)//1 Sec has elapsed 
	 {
		TimeValue = TimeValueNew;
		//GetindividualCellVoltages
		//Deduce Which Switches to Make/Break
		RankCellsBasedOnVoltage(CellSorter);
		SortCellsbyRank(CellSorter);
		SetSwitchState(CellSorter,SwitchArray);
		//Compute Individual Cell Currents Drawn
		ComputeCurrentsDrawnFromIndividualCells(CellSorter);
		//Compute Energy Drawn
		//Update Voltages,And Capacity
		UpdateCellCapacityAndVoltagesEverySecond();
		//Update GUI
		UpdateGUI();
	 }
		

	}
	

}
void Battery::SetSwitchState(Simulator::CellHolder * In,Simulator::SwitchHolder * SwIn)
{
	if(In[0].Cell.GetPotential()-In[2].Cell.GetPotential()<50)
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(1);
	}
	else if(In[0].Cell.GetPotential()-In[1].Cell.GetPotential()<50)
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(0);
	}
	else
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(0);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(0);	
	}
	
}
void Battery::ComputeCurrentsDrawnFromIndividualCells(Simulator::CellHolder * In)
{
	Resistance TotalResistanceBranchOneComponent=ResistorOne.GetResistance()+
						CellOne.GetInternalResistance().GetResistance(),
			TotalResistanceBranchTwoComponent=ResistorTwo.GetResistance()+
						CellTwo.GetInternalResistance().GetResistance(),
			TotalResistanceBranchThreeComponent=ResistorThree.GetResistance()+
						CellThree.GetInternalResistance().GetResistance(),						
	TotalResistanceCellsCombinedComponent=0;
	if(SwitchOne.GetSwitch()==1)
	{
		TotalResistanceCellsCombinedComponent+=1/TotalResistanceBranchOneComponent;
	}
	if(SwitchTwo.GetSwitch()==1)
	{
		TotalResistanceCellsCombinedComponent+=1/TotalResistanceBranchTwoComponent;
	}
	if(SwitchThree.GetSwitch()==1)
	{
		TotalResistanceCellsCombinedComponent+=1/TotalResistanceBranchThreeComponent;
	}
	TotalResistanceCellsCombinedComponent=1/TotalResistanceCellsCombinedComponent;
	float TotalCircutResistance=
		TotalResistanceCellsCombinedComponent+ResistorLoad.GetResistance();
	Voltage DCBusVoltage=0;
	{
		SwitchHolder SwitchArray[3]={SwitchOne,SwitchTwo,SwitchThree};
		for(std::uint8_t i=0;i<3;i++)
		{
			if(SwitchArray[In[i].CellCount-1].Switch.GetSwitch()==1)
			{
				DCBusVoltage=In[i].Cell.GetPotential();
			}
		}
	}
	float TotalLoadCurrent=DCBusVoltage/TotalCircutResistance;
	Voltage VoltageDropBetweenThreeCells=DCBusVoltage-(TotalLoadCurrent*ResistorLoad.GetResistance());
	if(SwitchOne.GetSwitch()==1)
	{
		CellOne.SetCurrent(VoltageDropBetweenThreeCells/TotalResistanceBranchOneComponent);
	}
	else CellOne.SetCurrent(0);
	if(SwitchTwo.GetSwitch()==1)
	{
		CellTwo.SetCurrent(VoltageDropBetweenThreeCells/TotalResistanceBranchTwoComponent);
	}
	else CellTwo.SetCurrent(0);
	if(SwitchThree.GetSwitch()==1)
	{
		CellThree.SetCurrent(VoltageDropBetweenThreeCells/TotalResistanceBranchThreeComponent);
	}
	else CellThree.SetCurrent(0);
}
/**
Computes the Charge consumed by the Cells and associated Voltage Drop.
Updates the Cells Voltage after the same.
*/
void Battery::UpdateCellCapacityAndVoltagesEverySecond()
{
	BatteryCapacity BatteryChargeConsumed=(CellOne.GetCurrent()/(float)3600)*Tempo;
	Voltage OriginalCellVoltage=CellOne.GetPotential();
	Voltage DropInBatteryVoltageAfterConsumption=(BatteryChargeConsumed*(Voltage)Globals::VoltageDropPermAh);
	Voltage NewCellVoltage=(Voltage)((Voltage)OriginalCellVoltage-DropInBatteryVoltageAfterConsumption);
	CellOne.SetPotentialVoltage(NewCellVoltage);
	BatteryChargeConsumed=(CellTwo.GetCurrent()/(float)3600)*Tempo;
	OriginalCellVoltage=CellTwo.GetPotential();
	DropInBatteryVoltageAfterConsumption=(BatteryChargeConsumed*(Voltage)Globals::VoltageDropPermAh);
	NewCellVoltage=(Voltage)((Voltage)OriginalCellVoltage-DropInBatteryVoltageAfterConsumption);
	CellTwo.SetPotentialVoltage(NewCellVoltage);
	BatteryChargeConsumed=(CellThree.GetCurrent()/(float)3600)*Tempo;
	OriginalCellVoltage=CellThree.GetPotential();
	DropInBatteryVoltageAfterConsumption=(BatteryChargeConsumed*(Voltage)Globals::VoltageDropPermAh);
	NewCellVoltage=(Voltage)((Voltage)OriginalCellVoltage-DropInBatteryVoltageAfterConsumption);
	CellThree.SetPotentialVoltage(NewCellVoltage);

}
void  Battery::UpdateGUI(void)
{
	printf("\r\nCells Status\r\n");
	printf("Cell One Status\r\n");
	printf("Voltage = %.6f Current = %.6f\r\n",CellOne.GetPotential(),CellOne.GetCurrent());
	printf("Cell Two Status\r\n");
	printf("Voltage = %.6f Current = %.6f\r\n",CellTwo.GetPotential(),CellTwo.GetCurrent());
	printf("Cell Three Status\r\n");
	printf("Voltage = %.6f Current = %.6f\r\n",CellThree.GetPotential(),CellThree.GetCurrent());
	printf("\r\nSwitches Status\r\n");
	printf("Switch One = %s\r\n",SwitchOne.GetSwitch()==1?"ON":"OFF");
	printf("Switch Two = %s\r\n",SwitchTwo.GetSwitch()==1?"ON":"OFF");
	printf("Switch Three = %s\r\n",SwitchThree.GetSwitch()==1?"ON":"OFF");
}


}//Simulator