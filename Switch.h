#ifndef BSIM_SWITCH_H
#define BSIM_SWITCH_H
#include <cstdint>
namespace Simulator{
  namespace CircuitElement{
typedef std::uint8_t SwitchState;  	
struct Switch{
Switch();
void SetSwitch(SwitchState);
SwitchState GetSwitch(void);
private:
SwitchState _SwitchState;
};//Switch
  }//CircuitElement
}//Simulator
#endif