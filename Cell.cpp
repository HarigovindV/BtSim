#include "Cell.h"

namespace Simulator{
  namespace CircuitElement{
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE()
{
  NON_IDEAL_DC_VOLTAGE_SOURCE(10,10);
}  
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE(Voltage VoltageInputValue,InternalResistance InternalResistanceInputValue)
{
  Set_Potential(VoltageInputValue);
  Set_internal_Resistance(InternalResistanceInputValue);
}
void NON_IDEAL_DC_VOLTAGE_SOURCE:SetPotentialVoltage(Voltage VoltageInputValue)
{
  _PotentialInmVolts=VoltageInputValue;
}
Voltage NON_IDEAL_DC_VOLTAGE_SOURCE:Voltage GetPotential(void)
{
  return _PotentialInmVolts;
}
void NON_IDEAL_DC_VOLTAGE_SOURCE:SetInternalResistance(InternalResistance InternalResistanceInputValue)
{
  _InternalResistanceInmOhms=InternalResistanceInputValue;
}
InternalResistance NON_IDEAL_DC_VOLTAGE_SOURCE:InternalResistance GetInternalResistance(void)
{
  return _InternalResistanceInmOhms;
}
void NON_IDEAL_DC_VOLTAGE_SOURCE:SetBatteryCapacity(BatteryCapacity BatteryCapacityInputValue)
{
  _BatteryCapacityInmAh=BatteryCapacityInputValue;
}
BatteryCapacity NON_IDEAL_DC_VOLTAGE_SOURCE:BatteryCapacity GetBatteryCapacity(void)
{
  return _BatteryCapacityInmAh;
}
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator
 
