#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
#include "Resistor.h"
typedef double Voltage;
typedef double BatteryCapacity;
typedef double Current;
typedef Simulator::CircuitElement::PURELY_IMPEDANCE_ONLY_ELEMENT InternalResistance;
namespace Simulator{
  namespace CircuitElement{
/**
	Abstraction For BatteryCell.Holds the Cell Voltage,ChargeCapacity,CurrentDrawn and Internal Resistance of the Cell
*/
struct NON_IDEAL_DC_VOLTAGE_SOURCE{
NON_IDEAL_DC_VOLTAGE_SOURCE();
NON_IDEAL_DC_VOLTAGE_SOURCE(Voltage VoltageInputValue);
void SetPotentialVoltage(Voltage);
Voltage GetPotential(void);
void SetInternalResistance(InternalResistance);
InternalResistance GetInternalResistance(void);
void SetBatteryCapacity(BatteryCapacity In);
BatteryCapacity GetBatteryCapacity(void);
void SetCurrent(Current);
Current GetCurrent(void);
private:
Voltage _PotentialInmVolts;
InternalResistance _InternalResistanceInmOhms;
BatteryCapacity _BatteryCapacityInmAh;
Current _CurrentInmAh;
};//DC_VOLTAGE_SOURCE
typedef struct NON_IDEAL_DC_VOLTAGE_SOURCE BatteryCell;
  }//CircuitElement
}//Simulator

#endif
