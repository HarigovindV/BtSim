#include "Switch.h"
namespace Simulator{
  namespace CircuitElement{
Switch::Switch()
{
  SetSwitch((SwitchState)0);
}  
void Switch::SetSwitch(SwitchState SwitchStateIPValue)
{
  _SwitchState=SwitchStateIPValue;
}  

SwitchState Switch::GetSwitch(void)
{
  return _SwitchState;
}

  }//CircuitElement
}//Simulator
 
