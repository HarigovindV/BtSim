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
void NON_IDEAL_DC_VOLTAGE_SOURCE:Set_PotentialVoltage(Voltage VoltageInputValue)
{
  Potential_in_Volts=VoltageInputValue;
}
Voltage NON_IDEAL_DC_VOLTAGE_SOURCE:Voltage Get_Potential(void)
{
  return Potential_in_Volts;
}
void NON_IDEAL_DC_VOLTAGE_SOURCE:Set_internal_Resistance(InternalResistance InternalResistanceInputValue)
{
  InternalResistance_in_mOhm=InternalResistanceInputValue;
}
InternalResistance NON_IDEAL_DC_VOLTAGE_SOURCE:InternalResistance Get_internal_Resistance(void)
{
  return InternalResistanceInputValue;
}
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator
 