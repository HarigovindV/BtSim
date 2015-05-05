#include "Battery.h"

#include "GlobalDeclarations.h"

#include <cstdio>
namespace Simulator{
void Battery::SetValues(Resistance ROne,Resistance RTwo,Resistance RThree,
		 Resistance RLoad,Voltage COne,Voltage CTwo,Voltage CThree)
{
	ResistorOne.SetResistance(ROne);
	ResistorTwo.SetResistance(RTwo);
	ResistorThree.SetResistance(RThree);
	ResistorLoad.SetResistance(RLoad);
	CellOne.SetPotentialVoltage(COne);
	CellTwo.SetPotentialVoltage(CTwo);
	CellThree.SetPotentialVoltage(CThree);
}
void Battery::GetVoltages(Voltage & COne,Voltage & CTwo,Voltage & CThree)
{

}
void Battery::GetSwitchStates(CircuitElement::SwitchState & SOne,CircuitElement::SwitchState &STwo,
					 CircuitElement::SwitchState & SThree)
{

}
void Battery::RunSim(void)
{
	/*Flow*/
	//GetindividualCellVoltages

	//Deduce Which Switches to Make/Break
	//Run For A Hour
	//Compute Individual Cell Currents Drawn
	//Compute Energy Drawn
	//Update Voltages,And Capacity
	//Update GUI
	/*Flow Ends Here*/
	while(1)
	{
	//GetindividualCellVoltages
	struct CellHolder CellSorter[3]={{CellOne,1,0},{CellTwo,2,0},{CellThree,3,0}};
	struct SwitchHolder SwitchArray[3]={SwitchOne,SwitchTwo,SwitchThree};
	//Deduce Which Switches to Make/Break
	RankCellsBasedOnVoltage(CellSorter);
	SortCellsbyRank(CellSorter);
	SetSwitchState(CellSorter,SwitchArray);
	SwitchOne.SetSwitch(SwitchArray[0].Switch.GetSwitch());
	SwitchTwo.SetSwitch(SwitchArray[1].Switch.GetSwitch());
	SwitchThree.SetSwitch(SwitchArray[2].Switch.GetSwitch());
	std::uint32_t time=0;
	while(time++);
	std::printf("1 hour elapsed\r\n");
	float I1,I2,I3;
	DeduceCurrents(CellSorter,I1,I2,I3);
	UpdateCellCapacityAndVoltagesEveryHour(I1,I2,I3);
	//Compute Individual Cell Currents Drawn
	//Compute Energy Drawn
	//Update Voltages,And Capacity
	//Update GUI
	}
	

}
void Battery::SetSwitchState(Simulator::CellHolder * In,Simulator::SwitchHolder * SwIn)
{
	/* Error-Inversed!!!*/
	if(In[0].Cell.GetPotential()-In[2].Cell.GetPotential()<50)
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(1);
	}
	else if(In[1].Cell.GetPotential()-In[2].Cell.GetPotential()<50)
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(0);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(1);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(1);
	}
	else
	{
		SwIn[(In[0].CellCount)-1].Switch.SetSwitch(0);
		SwIn[(In[1].CellCount)-1].Switch.SetSwitch(0);
		SwIn[(In[2].CellCount)-1].Switch.SetSwitch(1);	
	}
	
}
void Battery::DeduceCurrents(Simulator::CellHolder * In,float &CurrentOne,float &CurrentTwo,float &CurrentThree)
{
	float TotalResistanceCellComponent=0;
	if(SwitchOne.GetSwitch()==1)
	{
		TotalResistanceCellComponent+=1/(ResistorOne.GetResistance()+CellOne.GetInternalResistance().GetResistance());
	}
	if(SwitchTwo.GetSwitch()==1)
	{
		TotalResistanceCellComponent+=(float)1/(float)((ResistorTwo.GetResistance()+CellTwo.GetInternalResistance().GetResistance()));
	}
	if(SwitchThree.GetSwitch()==1)
	{
		TotalResistanceCellComponent+=1/(ResistorThree.GetResistance()+CellThree.GetInternalResistance().GetResistance());
	}

	TotalResistanceCellComponent=1/TotalResistanceCellComponent;
	float TotalCircutResistance=
		TotalResistanceCellComponent+(float)ResistorLoad.GetResistance();
	Voltage DCBusVoltage=In[2].Cell.GetPotential();
	float TotalLoadCurrent=DCBusVoltage/TotalCircutResistance;
	if(SwitchOne.GetSwitch()==1)
	{
		CurrentOne=DCBusVoltage/(ResistorOne.GetResistance()+CellOne.GetInternalResistance().GetResistance());
	}
	else CurrentOne=0;
	if(SwitchTwo.GetSwitch()==1)
	{
		CurrentTwo=DCBusVoltage/(ResistorTwo.GetResistance()+CellTwo.GetInternalResistance().GetResistance());
	}
	else CurrentTwo=0;
	if(SwitchThree.GetSwitch()==1)
	{
		CurrentThree=DCBusVoltage/(ResistorThree.GetResistance()+CellThree.GetInternalResistance().GetResistance());
	}
	else CurrentThree=0;
}
void Battery::UpdateCellCapacityAndVoltagesEveryHour(float CurrentOne,float CurrentTwo,float CurrentThree)
{
	CellOne.SetBatteryCapacity(CellOne.GetBatteryCapacity()-CurrentOne);
	CellTwo.SetBatteryCapacity(CellOne.GetBatteryCapacity()-CurrentTwo);
	CellThree.SetBatteryCapacity(CellOne.GetBatteryCapacity()-CurrentThree);
	CellOne.SetPotentialVoltage(CellOne.GetPotential()-CurrentOne*Globals::VoltageDropPermAh);
	CellTwo.SetPotentialVoltage(CellTwo.GetPotential()-CurrentTwo*Globals::VoltageDropPermAh);
	CellThree.SetPotentialVoltage(CellThree.GetPotential()-CurrentThree*Globals::VoltageDropPermAh);
}


}//Simulator