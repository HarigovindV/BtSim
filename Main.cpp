#include "Battery.h"
#include "GlobalDeclarations.h"
#include<cstdio>
int main()
{
	std::printf("Battery Simulator Program");
	std::printf("Reading BatteryData.txt");
	FILE * ConfigFIle=fopen("BatteryData.txt","r");
	if(ConfigFIle==0)
	{
		std::printf("Error Reading BatteryData.txt\r\nProgram Will Now Exit");
		return -1;
	}
	std::uint8_t TextLineFromFile[200]={},*TextLinePointer=TextLineFromFile;
	std::uint8_t Temp;
	std::uint8_t Limit=200;
while(Limit)
{
	Temp=getc(ConfigFIle);
	if(Temp==EOF)break;
	*(TextLinePointer++)=Temp;
	Limit--;
}
fgets((char *)TextLineFromFile, sizeof(TextLineFromFile)-1, ConfigFIle);
Voltage CellOneTemp,CellTwoTemp,CellThreeTemp;
Resistance ResistorOneTemp,ResistorTwoTemp,ResistorThreeTemp,
ResistorLoadTemp;
SimulationSpeed SpeedTemp;
std::sscanf((char *)TextLineFromFile,"CellOne=%lf&CellTwo=%lf&CellThree=%lf&ResistorOne=%lf"
"&ResistorTwo=%lf&ResistorThree=%lf&LoadResistor=%lf&Tempo=%lf",&
CellOneTemp,&CellTwoTemp,&CellThreeTemp,&
ResistorOneTemp,&ResistorTwoTemp,&ResistorThreeTemp,&
ResistorLoadTemp,&SpeedTemp);
	Simulator::Battery DischargingBat;
	DischargingBat.SetValues(CellOneTemp,CellTwoTemp,CellThreeTemp,
	ResistorOneTemp,ResistorTwoTemp,ResistorThreeTemp,
	ResistorLoadTemp,SpeedTemp);
	bool DataValid=true;
	if(CellOneTemp>Simulator::Globals::MaximumCellVoltage || CellOneTemp<Simulator::Globals::MinimumCellVoltage)
	{
		DataValid=false;
	}
	if(CellTwoTemp>Simulator::Globals::MaximumCellVoltage || CellTwoTemp<Simulator::Globals::MinimumCellVoltage)
	{
		DataValid=false;
	}
	if(CellThreeTemp>Simulator::Globals::MaximumCellVoltage || CellThreeTemp<Simulator::Globals::MinimumCellVoltage)
	{
		DataValid=false;
	}
	if(SpeedTemp<=0)
	{
		DataValid=false;
	}
	if(!DataValid)
	{
		printf("Data Invalid.Please Check the Data You have Loaded\r\n");
		return -2;
	}

	DischargingBat.RunSim();
}