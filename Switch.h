#ifndef BSIM_SWITCH_H
#define BSIM_SWITCH_H
#include <cstdint>
namespace Simulator{
  namespace CircuitElement{
typedef std::uint8_t SwitchState;
/**
	Abstraction For Switch.Has Only single Property,SwitchState which holds the Switch the ON/OFF Status.
*/
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