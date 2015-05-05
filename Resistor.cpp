#include "Resistor.h"
namespace Simulator{
  namespace CircuitElement{
PURELY_IMPEDANCE_ONLY_ELEMENT::PURELY_IMPEDANCE_ONLY_ELEMENT()
{
  PURELY_IMPEDANCE_ONLY_ELEMENT(10);
}
PURELY_IMPEDANCE_ONLY_ELEMENT::PURELY_IMPEDANCE_ONLY_ELEMENT(Resistance In)
{
	_ResistanceInmOhms=In;
}
void PURELY_IMPEDANCE_ONLY_ELEMENT::SetResistance(Resistance ResistanceInputValue)
{
  _ResistanceInmOhms=ResistanceInputValue;
}  

Resistance PURELY_IMPEDANCE_ONLY_ELEMENT::GetResistance(void)
{
  return _ResistanceInmOhms;
}
  }//CircuitElement
}//Simulator
 
