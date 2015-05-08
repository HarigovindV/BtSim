#ifndef BSIM_RESISTOR_H
#define BSIM_RESISTOR_H
#include <cstdint>
typedef double Resistance;
namespace Simulator{
  namespace CircuitElement{
typedef struct PURELY_IMPEDANCE_ONLY_ELEMENT Resistor;
/**
	Abstraction For Resistor.Has Only single Property,Resistance which is Implemented via 
	private variable accessible via Properties.
*/
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