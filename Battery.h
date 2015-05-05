#ifndef BSIM_BATTERY_H
#define BSIM_BATTERY_H
#include "Cell.h"
#include "Resistor.h"
#include "Switch.h"
namespace Simulator{
struct  CellHolder
{
	CircuitElement::BatteryCell Cell;
	std::uint8_t CellCount;
	std::uint8_t CellVoltageRank;
};
struct  SwitchHolder
{
	CircuitElement::Switch Switch;
};
class Battery{

CircuitElement::Resistor ResistorOne,ResistorTwo,ResistorThree,ResistorLoad;
CircuitElement::BatteryCell CellOne,CellTwo,CellThree;
CircuitElement::Switch  SwitchOne,SwitchTwo,SwitchThree;
public:
void SetValues(Resistance ROne,Resistance RTwo,Resistance RThree,
		 Resistance RLoad,Voltage COne,Voltage CTwo,Voltage CThree);
void GetVoltages(Voltage & COne,Voltage & CTwo,Voltage & CThree);
void GetSwitchStates(CircuitElement::SwitchState & SOne,CircuitElement::SwitchState &STwo,
					 CircuitElement::SwitchState & SThree);
void RunSim(void);
void SetSwitchState(Simulator::CellHolder * In,Simulator::SwitchHolder * SwIn);
void DeduceCurrents(Simulator::CellHolder * In,float &CurrentOne,float &CurrentTwo,float &CurrentThree);
void UpdateCellCapacityAndVoltagesEveryHour(float CurrentOne,float CurrentTwo,float CurrentThree);
};
}
void RankCellsBasedOnVoltage(Simulator::CellHolder * In);
void SortCellsbyRank(Simulator::CellHolder * In);



#endif