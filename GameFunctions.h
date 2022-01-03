#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern struct Inventory
{
	bool inInventory;
	string name;
};

extern Inventory map;
extern Inventory food;
extern Inventory drink;
extern Inventory toy;
extern Inventory weapon;
extern Inventory hoardKey;
extern Inventory armoryKey;
extern Inventory cellKey;
extern Inventory throneKey;

void DisplayInventory();
void ClearInput();
void ValidDecision(string &yesNo);
int ValidInsultChoice(int insultChoice);
void ContInsult(int &playerChoice);
int AddInfamy(int totalInfamy);
void DisplayTotalGold(int totalGold);
string ChooseToLoot();
void LootGold(int goldLoot, int &totalGold);
void EmptyBarrel();
void CurrentLocation(string loc, string locDescript);
void ChangeArea(string direction, string area);
void ChangeRoom(string direction, string area);
string ContinueGame(string gameCondition);

#endif

