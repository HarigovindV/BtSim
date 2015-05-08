#include "Cell.h"
#include "GlobalDeclarations.h"
namespace Simulator{
  namespace CircuitElement{
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE()
{
  NON_IDEAL_DC_VOLTAGE_SOURCE(10000);
  SetInternalResistance(Simulator::Globals::DefaultInternalResistanceValueInmAh);
}  
NON_IDEAL_DC_VOLTAGE_SOURCE::NON_IDEAL_DC_VOLTAGE_SOURCE(Voltage VoltageInputValue)
{
  SetPotentialVoltage(VoltageInputValue);
}
void NON_IDEAL_DC_VOLTAGE_SOURCE::SetPotentialVoltage(Voltage VoltageInputValue)
{
  _PotentialInmVolts=VoltageInputValue;
  BatteryCapacity Current=(Simulator::Globals::MaximumCellCapacity);
  Current-=(Simulator::Globals::MaximumCellVoltage-VoltageInputValue)/Simulator::Globals::VoltageDropPermAh;
  SetBatteryCapacity(Current);
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
void NON_IDEAL_DC_VOLTAGE_SOURCE::SetCurrent(Current CellCurrentInputValue)
{
  _CurrentInmAh=CellCurrentInputValue;
}
Current NON_IDEAL_DC_VOLTAGE_SOURCE::GetCurrent(void)
{
  return _CurrentInmAh;
}

  }//CircuitElement
}//Simulator
 
