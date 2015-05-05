#ifndef SIM_GLBL_DEC
#define SIM_GLBL_DEC
#include "Cell.h"
namespace Simulator{
	namespace Globals{
Voltage MaximumCellVoltage=12000;
Voltage MinimumCellVoltage=7500;
BatteryCapacity MaximumCellCapacity=4500;
BatteryCapacity MinimumCellCapacity=0;
float VoltageDropPermAh=(MaximumCellVoltage-MinimumCellVoltage)/(MaximumCellCapacity-MinimumCellCapacity);
	}//Globals
}//Simulator
#endif