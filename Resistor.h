#ifndef BSIM_RESISTOR_H
#define BSIM_RESISTOR_H
#include <cstdint>
typedef std::uint16_t Resistance
typedef Simulator::CircuitElement::PURELY_IMPEDANCE_ONLY_ELEMENT Resistor
namespace Simulator{
  namespace CircuitElement{
struct PURELY_IMPEDANCE_ONLY_ELEMENT{
PURELY_IMPEDANCE_ONLY_ELEMENT();
SetResistance(Resistance);
Resistance GetResistance(void);
private:
Resistance _ResistanceInmOhms;
}//PURELY_IMPEDANCE_ONLY_ELEMENT
  }//CircuitElement
}//Simulator