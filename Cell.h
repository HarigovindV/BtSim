#ifndef BSIM_CELL_H
#define BSIM_CELL_H
#include <cstdint>
namespace Simulator{
  namespace CircuitElement{
struct NON_IDEAL_DC_VOLTAGE_SOURCE{
NON_IDEAL_DC_VOLTAGE_SOURCE();
Set_Potential();
Get_Potential();
Set_internal_Resistance();
Get_internal_Resistance();
private:
std::uint8_t Potential_in_Volts;
std::uint8_t InternalResistance_in_mOhm;
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator

#endif
