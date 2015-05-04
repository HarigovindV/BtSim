#include "Resistor.h"
namespace Simulator{
  namespace CircuitElement{
PURELY_IMPEDANCE_ONLY_ELEMENT::PURELY_IMPEDANCE_ONLY_ELEMENT()
{
  PURELY_IMPEDANCE_ONLY_ELEMENT(10);
}  
PURELY_IMPEDANCE_ONLY_ELEMENT::SetResistance(Resistance ResistanceInputValue)
{
  _ResistanceInmOhms=ResistanceInputValue;
}  

PURELY_IMPEDANCE_ONLY_ELEMENT:Resistance GetResistance(void)
{
  return _ResistanceInmOhms;
}
}//DC_VOLTAGE_SOURCE
  }//CircuitElement
}//Simulator
 
