#include "Battery.h"
int main()
{
	Simulator::Battery DischargingBat;
	DischargingBat.SetValues(100,200,300,300,12000,10049,10100);
	DischargingBat.RunSim();
}