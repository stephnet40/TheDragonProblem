#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CharList.h"
#include "GameFunctions.h"

using namespace std;

extern TownGuard entryGuard;
extern TownGuard exitGuard;
extern TownGuard marketGuard;
extern Citizen beggar;
extern Citizen angryCitizen;
extern Citizen concernedCitizen;
extern Citizen prisoner;
extern Citizen mayor;
extern Vendor shopkeep;
extern Vendor blacksmith;
extern Vendor barkeep;
extern Minion minionGuard;
extern Minion minionServant;
extern Dragon dragonLord;
extern Dragon dragonWife;
extern Dragon dragonChild;

void ApproachGuard();
void TalkToEntryGuard();
void EntryAskTown();
void EntryAskRumors();
int EntryInsult();
void LeaveEntryConversation();
void ExamineEntryBarrel(int &barrelGold, int &totalGold, int &numLootStolen);
void LeaveTown();