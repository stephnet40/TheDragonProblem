#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

TownGuard CreateEntryGuard(TownGuard entryGuard);
TownGuard CreateExitGuard(TownGuard exitGuard);
TownGuard CreateMarketGuard(TownGuard marketGuard);

Citizen CreateBeggar(Citizen beggar);
Citizen CreateAngryCitizen(Citizen angryCitizen);
Citizen CreateConcernedCitizen(Citizen concernedCitizen);
Citizen CreatePrisoner(Citizen prisoner);
Citizen CreateMayor(Citizen mayor);

Vendor CreateShopkeep(Vendor shopkeep);
Vendor CreateBlacksmith(Vendor blacksmith);
Vendor CreateBarkeep(Vendor barkeep);

Minion CreateMinionGuard(Minion guard);
Minion CreateMinionServant(Minion servant);

Dragon CreateDragonLord(Dragon lord);
Dragon CreateDragonWife(Dragon wife);
Dragon CreateDragonChild(Dragon child);
