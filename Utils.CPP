#include "Battery.h"


/**
Computes the Ranks of Cells based On Voltages
Total 13 Different Rankings are Possible
if 1 to 3 Ranks are Assigned 3*2*1 =6 Possbile permutations
if 1 and 2 Ranks are assigned (Two Cells may have identical Voltages) 6 Possible permutations
if All cells have same voltage 1 permutations
	
*/
void RankCellsBasedOnVoltage(Simulator::CellHolder * In)
{
	if(In[0].Cell.GetPotential() == In[1].Cell.GetPotential() && In[1].Cell.GetPotential() == In[2].Cell.GetPotential())	//111
	{
		In[0].CellVoltageRank=	
		In[1].CellVoltageRank=
		In[2].CellVoltageRank=1;
	}
	else if(In[0].Cell.GetPotential()<In[1].Cell.GetPotential())
	{
		In[0].CellVoltageRank=3;
		In[1].CellVoltageRank=2;
		if(In[1].Cell.GetPotential()<In[2].Cell.GetPotential())
		{
			In[2].CellVoltageRank=1;            //321
		}
		else if(In[1].Cell.GetPotential()==In[2].Cell.GetPotential())
		{
			In[1].CellVoltageRank=				//211		
			In[2].CellVoltageRank=1;		
			In[0].CellVoltageRank=2;
		}
		else if(In[1].Cell.GetPotential()>In[2].Cell.GetPotential())		//3** 
		{
			if(In[2].Cell.GetPotential()==In[0].Cell.GetPotential())	//212
			{
				In[1].CellVoltageRank=1;		
				In[0].CellVoltageRank=
				In[2].CellVoltageRank=2;
			}
			else if(In[2].Cell.GetPotential()>In[0].Cell.GetPotential())//312
			{
				In[0].CellVoltageRank=3;
				In[1].CellVoltageRank=1;		
				In[2].CellVoltageRank=2;
			}
			else											//213
			{
				In[0].CellVoltageRank=2;			
				In[1].CellVoltageRank=1;		
				In[2].CellVoltageRank=3;
			} 
		}

	}
	else if(In[0].Cell.GetPotential()==In[1].Cell.GetPotential()) 
	{
		if(In[2].Cell.GetPotential()>In[0].Cell.GetPotential())   //221
		{
			In[0].CellVoltageRank=
			In[1].CellVoltageRank=2;	
			In[2].CellVoltageRank=1;	
		}
		if(In[2].Cell.GetPotential()<In[0].Cell.GetPotential())   //112
		{
			In[0].CellVoltageRank=
			In[1].CellVoltageRank=1;	
			In[2].CellVoltageRank=2;	
		}
	}
	else if(In[0].Cell.GetPotential()>In[1].Cell.GetPotential())
	{
		if(In[1].Cell.GetPotential()==In[2].Cell.GetPotential())		//122
		{
			In[0].CellVoltageRank=1;
			In[1].CellVoltageRank=2;	
			In[2].CellVoltageRank=2;		
		}
		else if(In[0].Cell.GetPotential()==In[2].Cell.GetPotential())	//121
		{
			In[0].CellVoltageRank=1;
			In[1].CellVoltageRank=2;	
			In[2].CellVoltageRank=1;		
		}
		else if(In[1].Cell.GetPotential()>In[2].Cell.GetPotential())		//123
		{
			In[0].CellVoltageRank=1;
			In[1].CellVoltageRank=2;	
			In[2].CellVoltageRank=3;		
		}
		else if(In[1].Cell.GetPotential()<In[2].Cell.GetPotential())		//*3*
		{
			if(In[0].Cell.GetPotential()<In[2].Cell.GetPotential())		//231
			{
				In[0].CellVoltageRank=2;
				In[1].CellVoltageRank=3;	
				In[2].CellVoltageRank=1;		
			}
			else											//132
			{
				In[0].CellVoltageRank=1;
				In[1].CellVoltageRank=3;	
				In[2].CellVoltageRank=2;
			}
		}		
	}
	return;
}
void SortCellsbyRank(Simulator::CellHolder * In)
{
	Simulator::CellHolder Temp[3]={};
	bool Rank1AlreadyAssigned=false,Rank2AlreadyAssigned=false,
	Rank1AlreadyAssignedTwice=false;
	for(std::uint8_t i=0;i<3;i++)
	{
		if(In[i].CellVoltageRank==1)
		{
			if(!Rank1AlreadyAssignedTwice)
			{
			if(!Rank1AlreadyAssigned)
			{
				Temp[0]=In[i];
				Rank1AlreadyAssigned=true;
			}
			else
			{
				if(Rank2AlreadyAssigned)
				{
					Temp[2]=Temp[1];
						
				}
				Temp[1]=In[i];	
				Rank1AlreadyAssignedTwice=true;
			}
			}
			else
			{
				Temp[2]=In[i];
			}
		}
		else if(In[i].CellVoltageRank==2)
		{
			if(!Rank1AlreadyAssignedTwice)
			{
				if(!Rank2AlreadyAssigned)
				{
					Temp[1]=In[i];
					Rank2AlreadyAssigned=true;
				}
				else
				{
					Temp[2]=In[i];	
				}
			}
			else
			{
				Temp[2]=In[i];	
			}

		}
		else if(In[i].CellVoltageRank==3)
		{
			Temp[2]=In[i];	
		}
	}
	for(std::uint8_t i=0;i<3;i++)
	{
		In[i]=Temp[i];
	}
	return;
}

