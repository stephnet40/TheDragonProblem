#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ShopsActions.h"

using namespace std;

void ApproachMayor();
void TalkToMayor();
void MayorAskDragon();
void MayorAskProblems();
int MayorInsult(int &totalGold);
void LeaveMayorConversation();

void ApproachHome(int &caughtStealing, int &totalGold, int &numLootStolen);

void ExamineHomeBarrel(int &barrelGold, int &totalGold, int &numLootStolen);

