#ifndef BSIM_RESISTOR_H
#define BSIM_RESISTOR_H
#include <cstdint>
typedef std::uint16_t Resistance;
namespace Simulator{
  namespace CircuitElement{
typedef struct PURELY_IMPEDANCE_ONLY_ELEMENT Resistor;
struct PURELY_IMPEDANCE_ONLY_ELEMENT{
PURELY_IMPEDANCE_ONLY_ELEMENT();
PURELY_IMPEDANCE_ONLY_ELEMENT(Resistance In);
void SetResistance(Resistance);
Resistance GetResistance(void);
private:
Resistance _ResistanceInmOhms;
};//PURELY_IMPEDANCE_ONLY_ELEMENT
  }//CircuitElement
}//Simulator
#endif