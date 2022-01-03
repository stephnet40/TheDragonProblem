#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "LairEntryActions.h"

using namespace std;

void EncounterMainServant(int &totalInfamy, bool &dealtWithServant);
void OpenThroneRoom(Inventory throneKey);
void OpenHoard(Inventory hoardKey, bool &unlocked);