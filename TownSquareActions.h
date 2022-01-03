#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "EntryActions.h"

using namespace std;

void ApproachBeggar();
void TalkToBeggar();
void BeggarAskRumors();
void BeggarAskStrange();
int BeggarInsult(int &totalGold);
void LeaveBeggarConversation();

void ApproachAngryCitizen();
void TalkToAngryCitizen();
void AngryAskProblem();
void AngryAskDragon(int &violentEnd);
int AngryInsult();
void AngryLeaveConversation();

void ApproachWell(Inventory &drink);