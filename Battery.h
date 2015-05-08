#ifndef BSIM_BATTERY_H
#define BSIM_BATTERY_H
#include "Cell.h"
#include "Resistor.h"
#include "Switch.h"
/**
 Used to Set the Speed of Simulation.SImulation is updated every second.
 Speed can be scaled up or down using this type.
 ex;Setting a VariableValue of 1 means normal speed.
 To speed up Simulation,Set Speed >1
 if(Speed == 3600)every second is assumed to be 1 hour.
 To slow down Simulation,Set Speed <1 but greater than 0
 if(Speed == 0.5)every second is assumed to be half second.
*/
typedef double SimulationSpeed;
namespace Simulator{
/**
	This  Structure is used to Make Calculations based on Cell Voltages easier.
	Holds a Cell,Its Count and Rank based ascending Voltage Values.
	This is Passed around for Calculations of 
		-Highest Voltage Cell,
		-Cells within 50mV Potential
*/
struct  CellHolder
{
	CircuitElement::BatteryCell Cell;
	std::uint8_t CellCount;
	std::uint8_t CellVoltageRank;
};
/**
	This  Structure is used to Make Switching On/Off easier.
	Holds Reference to a Switch
*/
struct  SwitchHolder
{
	CircuitElement::Switch &Switch;
};
/**
	Abstraction For Battery.It consists of Three Cells in Three separate Branches of the Circuit,controlled 
	via Three individual Switches.Also Has Three Branch Resistances and A Load Resistance
*/
class Battery{

CircuitElement::Resistor ResistorOne,ResistorTwo,ResistorThree,ResistorLoad;
CircuitElement::BatteryCell CellOne,CellTwo,CellThree;
CircuitElement::Switch  SwitchOne,SwitchTwo,SwitchThree;
Current LoadCurrent;
SimulationSpeed Tempo;
public:
void SetValues(Resistance ROne,Resistance RTwo,Resistance RThree,
		 Resistance RLoad,Voltage COne,Voltage CTwo,Voltage CThree,SimulationSpeed Speed);
void GetVoltages(Voltage & COne,Voltage & CTwo,Voltage & CThree);
void GetSwitchStates(CircuitElement::SwitchState & SOne,CircuitElement::SwitchState &STwo,
					 CircuitElement::SwitchState & SThree);
void RunSim(void);
void SetSwitchState(Simulator::CellHolder * In,Simulator::SwitchHolder * SwIn);
void ComputeCurrentsDrawnFromIndividualCells(Simulator::CellHolder * In);
void UpdateCellCapacityAndVoltagesEverySecond();
void UpdateGUI(void);
};
}




#endif