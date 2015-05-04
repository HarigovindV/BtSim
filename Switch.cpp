#include "Switch.h"
namespace Simulator{
  namespace CircuitElement{
Switch::Switch()
{
  Switch(0);
}  
Switch::SetSwitch(SwitchState SwitchStateIPValue)
{
  _SwitchState=SwitchStateIPValue;
}  

Switch:SwitchState GetSwitch(void)
{
  return _SwitchState;
}
}//Switch
  }//CircuitElement
}//Simulator
 
