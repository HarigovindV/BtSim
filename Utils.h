#ifndef BSIM_UTILS_H
#define BSIM_UTILS_H
#include "Battery.h"
#include <cstdint>
void RankCellsBasedOnVoltage(Simulator::CellHolder * In);
void SortCellsbyRank(Simulator::CellHolder * In);
#endif