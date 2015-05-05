#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
#include "Resistor.h"
typedef std::int16_t Voltage;
typedef std::uint16_t BatteryCapacity;
namespace Simulator{
  namespace CircuitElement{
typedef struct PURELY_IMPEDANCE_ONLY_ELEMENT InternalResistance;
struct NON_IDEAL_DC_VOLTAGE_SOURCE{
NON_IDEAL_DC_VOLTAGE_SOURCE();
NON_IDEAL_DC_VOLTAGE_SOURCE(Voltage VoltageInputValue,InternalResistance InternalResistanceInputValue);
void SetPotentialVoltage(Voltage);
Voltage GetPotential(void);
void SetInternalResistance(InternalResistance);
InternalResistance GetInternalResistance(void);
void SetBatteryCapacity(BatteryCapacity In);
BatteryCapacity GetBatteryCapacity(void);
private:
Voltage _PotentialInmVolts;
InternalResistance _InternalResistanceInmOhms;
BatteryCapacity _BatteryCapacityInmAh;
};//DC_VOLTAGE_SOURCE
typedef struct NON_IDEAL_DC_VOLTAGE_SOURCE BatteryCell;
  }//CircuitElement
}//Simulator

#endif
