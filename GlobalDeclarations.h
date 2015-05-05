#ifndef SIM_GLBL_DEC
#define SIM_GLBL_DEC
#include "Cell.h"
namespace Simulator{
	namespace Globals{
static const Voltage MaximumCellVoltage=12000;
static const Voltage MinimumCellVoltage=7500;
static const BatteryCapacity MaximumCellCapacity=4500;
static const BatteryCapacity MinimumCellCapacity=0;
static const float VoltageDropPermAh=(MaximumCellVoltage-MinimumCellVoltage)/(MaximumCellCapacity-MinimumCellCapacity);
static const InternalResistance DefaultInternalResistanceValueInmAh;
	}//Globals
}//Simulator
#endif