#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
typedef std::int16_t Voltage
typedef std::uint16_t InternalResistance
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
Voltage _PotentialInmVolts;
InternalResistance _InternalResistanceInmOhms;
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator

#endif
