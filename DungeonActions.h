#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MinionQuartersActions.h"

using namespace std;

void EncounterDungeonGuard(int &totalInfamy, bool &foughtGuard, bool &bribedGuard);
void ApproachPrisoner();
void CellUnlocked();
void UnlockCell(int &totalInfamy, bool foughtGuard, bool bribedGuard, bool &unlocked);