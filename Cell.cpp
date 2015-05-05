#include "Cell.h"

namespace Simulator{
  namespace CircuitElement{
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE()
{
  NON_IDEAL_DC_VOLTAGE_SOURCE((Voltage)10,(InternalResistance)10);
}  
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE(Voltage VoltageInputValue,InternalResistance InternalResistanceInputValue)
{
  SetPotentialVoltage(VoltageInputValue);
  SetInternalResistance(InternalResistanceInputValue);
}
void NON_IDEAL_DC_VOLTAGE_SOURCE::SetPotentialVoltage(Voltage VoltageInputValue)
{
  _PotentialInmVolts=VoltageInputValue;
}
Voltage NON_IDEAL_DC_VOLTAGE_SOURCE::GetPotential(void)
{
  return _PotentialInmVolts;
}
void NON_IDEAL_DC_VOLTAGE_SOURCE::SetInternalResistance(InternalResistance InternalResistanceInputValue)
{
  _InternalResistanceInmOhms=InternalResistanceInputValue;
}
InternalResistance NON_IDEAL_DC_VOLTAGE_SOURCE::GetInternalResistance(void)
{
  return _InternalResistanceInmOhms;
}
void NON_IDEAL_DC_VOLTAGE_SOURCE::SetBatteryCapacity(BatteryCapacity BatteryCapacityInputValue)
{
  _BatteryCapacityInmAh=BatteryCapacityInputValue;
}
BatteryCapacity NON_IDEAL_DC_VOLTAGE_SOURCE::GetBatteryCapacity(void)
{
  return _BatteryCapacityInmAh;
}

  }//CircuitElement
}//Simulator
 
