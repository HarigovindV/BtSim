#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
typedef std::int8_t Voltage
typedef std::int8_t InternalResistance
typedef Simulator::CircuitElement::NON_IDEAL_DC_VOLTAGE_SOURCE BatteryCell
namespace Simulator{
  namespace CircuitElement{
struct NON_IDEAL_DC_VOLTAGE_SOURCE{
NON_IDEAL_DC_VOLTAGE_SOURCE();
Set_PotentialVoltage(Voltage);
Voltage Get_Potential(void);
Set_internal_Resistance(InternalResistance);
InternalResistance Get_internal_Resistance(void);
private:
Voltage Potential_in_Volts;
InternalResistance InternalResistance_in_mOhm;
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator

#endif
