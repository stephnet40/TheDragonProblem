#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "GameFunctions.h"

using namespace std;

extern Inventory map{ false, "" };
extern Inventory food{ false, "" };
extern Inventory drink{ false, "" };
extern Inventory toy{ false, "" };
extern Inventory weapon{ false, "" };
extern Inventory hoardKey{ false, "" };
extern Inventory armoryKey{ false, "" };
extern Inventory cellKey{ false, "" };
extern Inventory throneKey{ false, "" };

void DisplayInventory()
{
	int inventoryItems = 0;

	cout << endl;

	if (map.inInventory == true)
	{
		cout << "  + " << map.name;
		inventoryItems++;
	}
		
	if (food.inInventory == true)
	{
		cout << "  + " << food.name;
		inventoryItems++;
	}

	if (drink.inInventory == true)
	{
		cout << "  + " << drink.name;
		inventoryItems++;
	}

	if (toy.inInventory == true)
	{
		cout << "  + " << toy.name;
		inventoryItems++;
	}

	if (weapon.inInventory == true)
	{
		cout << "  + " << weapon.name;
		inventoryItems++;
	}

	if (hoardKey.inInventory == true)
	{
		cout << "  + " << hoardKey.name;
		inventoryItems++;
	}

	if (armoryKey.inInventory == true)
	{
		cout << "  + " << armoryKey.name;
		inventoryItems++;
	}

	if (cellKey.inInventory == true)
	{
		cout << "  + " << cellKey.name;
		inventoryItems++;
	}

	if (throneKey.inInventory == true)
	{
		cout << "  + " << throneKey.name;
		inventoryItems++;
	}

	if (inventoryItems == 0)
	{
		cout << "Your inventory is empty.";
	}

	cout << endl << endl;
}

void ClearInput()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Invalid input. Try again." << endl << endl;
}

void ValidDecision(string &yesNo)
{
	while (yesNo != "Y" && yesNo != "y" && yesNo != "N" && yesNo != "n")
	{
		cout << endl;
		cout << "Invalid input. Try again." << endl << endl;
		cin >> yesNo;
	}
}

int ValidInsultChoice(int insultChoice)
{
	while (!insultChoice || (insultChoice != 1 && insultChoice != 2))
	{
		ClearInput();
		cin >> insultChoice;
	}

	return insultChoice;
}

void ContInsult(int &playerChoice)
{
	cout << "1. Insult again" << endl;
	cout << "2. Back to topic list" << endl << endl;

	cin >> playerChoice;
	playerChoice = ValidInsultChoice(playerChoice);
	cout << endl;
}

// Counter for both testing character patience and couting number of times things have been looted
int AddInfamy(int totalInfamy) 
{
	totalInfamy++;
	return totalInfamy;
}

void DisplayTotalGold(int totalGold)
{
	cout << "Total Gold: " << totalGold << endl << endl;
}

void LootGold(int goldLoot, int &totalGold)
{
	totalGold += goldLoot;
}

string ChooseToLoot()
{
	string playerAnswer;
	cout << "Loot the barrel? (y/n)" << endl;
	cout << endl;
	cin >> playerAnswer;
	ValidDecision(playerAnswer);

	return playerAnswer;
}

void EmptyBarrel()
{
	cout << endl;
	cout << "The barrel is empty." << endl << endl;
}

void CurrentLocation(string loc, string locDescript)
{
	cout << "You are " << loc << "." << endl << endl;
	cout << locDescript << endl << endl;
}

void ChangeArea(string direction, string area)
{
	cout << endl;
	cout << "You head " << direction << ", " << area << endl << endl;
}

void ChangeRoom(string direction, string area)
{
	cout << endl;
	cout << "You head through the " << direction << ", " << area << endl << endl;
}

string ContinueGame(string gameCondition)
{
	string startOver;
	if (gameCondition == "game over")
	{
		cout << "Your journey has ended in defeat. Would you like to try again? (y/n)" << endl << endl;
	}
	else if (gameCondition == "violent end")
	{
		cout << "You've successfully defeated the dragon! Would you like to restart? (y/n)" << endl << endl;
	}
	else
	{
		cout << "You've made peace between the dragon and the town! Would you like to restart? (y/n)" << endl << endl;
	}

	cin >> startOver;
	ValidDecision(startOver);
	cout << endl;

	return startOver;
}
