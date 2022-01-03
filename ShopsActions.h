#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MarketActions.h"

using namespace std;

void ApproachBarkeep(int &totalGold, int &totalInfamy, Inventory &map, Inventory &food);
void ApproachShopkeep(int &totalGold, int &totalInfamy, Inventory &hoardKey, Inventory &toy, int &peaceEnd);
void ApproachBlacksmith(int &totalGold, int &totalInfamy, Inventory &armoryKey, Inventory &weapon, int &violentEnd);

void ExitBuilding();