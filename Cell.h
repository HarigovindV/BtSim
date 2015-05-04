#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
#include "Resistor.h"
typedef std::int16_t Voltage;
typedef Resistor InternalResistance;
typedef std::uin16_t BatteryCapacity;
typedef Simulator::CircuitElement::NON_IDEAL_DC_VOLTAGE_SOURCE BatteryCell
namespace Simulator{
  namespace CircuitElement{
struct NON_IDEAL_DC_VOLTAGE_SOURCE{
NON_IDEAL_DC_VOLTAGE_SOURCE();
SetPotentialVoltage(Voltage);
Voltage GetPotential(void);
SetInternalResistance(InternalResistance);
InternalResistance GetInternalResistance(void);
void SetBatteryCapacity(BatteryCapacity In);
BatteryCapacity GetBatteryCapacity(void);

private:
Voltage _PotentialInmVolts;
InternalResistance _InternalResistanceInmOhms;
BatteryCapacity _BatteryCapacityInmAh;
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator

#endif
