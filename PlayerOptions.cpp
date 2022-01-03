#include <iostream>
#include <string>
#include "PlayerOptions.h"

using namespace std;

void ActionPrompt()
{
	cout << "What will you do?" << endl;
	cout << endl;
}

// Town Entrance
void EntranceAction()
{
	ActionPrompt();
	cout << "1. Talk to Guard" << endl;
	cout << "2. Loot barrel" << endl;
	cout << "3. Display inventory" << endl;
	cout << "4. Go north to Town Square" << endl;
	cout << "5. Got south to leave town" << endl;
	cout << endl;
}

// Town Square
void TownSquareAction()
{
	ActionPrompt();
	cout << "1. Talk to Beggar" << endl;
	cout << "2. Talk to Angry Citizen" << endl;
	cout << "3. Approach town well" << endl;
	cout << "4. Display inventory" << endl;
	cout << "5. Go north to the Town Exit" << endl;
	cout << "6. Go east to the Market" << endl;
	cout << "7. Go west to the Village Homes" << endl;
	cout << "8. Go south to Town Entrance" << endl;
	cout << endl;
}

// Residential
void ResidentialAction()
{
	ActionPrompt();
	cout << "1. Talk to Mayor" << endl;
	cout << "2. Take a look at a home" << endl;
	cout << "3. Loot barrel" << endl;
	cout << "4. Display inventory" << endl;
	cout << "5. Go east to Town Square" << endl;
	cout << endl;
}

// Market
void MarketAction()
{
	ActionPrompt();
	cout << "1. Talk to Concerned Citizen" << endl;
	cout << "2. Loot barrels" << endl;
	cout << "3. Pickpocket Unsuspecting Citizen" << endl;
	cout << "4. Display inventory" << endl;
	cout << "5. Enter the Tavern" << endl;
	cout << "6. Enter the General Store" << endl; 
	cout << "7. Enter the Smithy" << endl;
	cout << "8. Go west to Town Square." << endl;
	cout << endl;
}

// Tavern
void TavernAction()
{
	ActionPrompt();
	cout << "1. Talk to Barkeep" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Return to Market" << endl;
	cout << endl;
}

// General Store
void GeneralStoreAction()
{
	ActionPrompt();
	cout << "1. Talk to Shopkeeper" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Return to Market" << endl;
	cout << endl;
}

// Blacksmith
void BlacksmithAction()
{
	ActionPrompt();
	cout << "1. Talk to Blacksmith" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Return to Market" << endl;
	cout << endl;
}

// Town Exit
void ExitAction()
{
	ActionPrompt();
	cout << "1. Talk to Guard" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Go north to Dragon Lair" << endl;
	cout << "4. Go south to Town Square" << endl;
	cout << endl;
}

// Lair Entrance

void LairEntryAction()
{
	ActionPrompt();
	cout << "1. Confront Minion Guard" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Go south to Town" << endl;
	cout << endl;
}

// Main Hall
void MainHallAction()
{
	ActionPrompt();
	cout << "1. Confront Minion Servant" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Open North Door to Throne Room" << endl;
	cout << "4. Open East Door to Dragon Hoard" << endl;
	cout << "5. Enter West Door to Side Hall" << endl;
	cout << endl;
}

// Side Hall
void SideHallAction()
{
	ActionPrompt();
	cout << "1. Confront Minion Servant" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Open West Door to Armory" << endl;
	cout << "4. Enter North Door to Minion Quarters" << endl;
	cout << "5. Enter South Door to Dungeons" << endl;
	cout << "6. Enter East Door to Main Hall" << endl;
	cout << endl;
}

// Dungeon
void DungeonAction()
{
	ActionPrompt();
	cout << "1. Confront Dungeon Guard" << endl;
	cout << "2. Talk to Prisoner" << endl;
	cout << "3. Unlock Cell" << endl;
	cout << "4. Display inventory" << endl;
	cout << "5. Return to Side Hall" << endl;
	cout << endl;
}

// Armory
void ArmoryAction()
{
	ActionPrompt();
	cout << "1. Examine Weapons" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Return to Side Hall" << endl;
	cout << endl;
}

// Minion Quarters
void MinionQuartersAction()
{
	ActionPrompt();
	cout << "1. Listen to off-duty minions" << endl;
	cout << "2. Steal from sleeping minion" << endl;
	cout << "3. Display inventory" << endl;
	cout << "4. Return to Side Hall" << endl;
	cout << endl;
}

// Hoard
void HoardAction()
{
	ActionPrompt();
	cout << "1. Examine treasure" << endl;
	cout << "2. Display inventory" << endl;
	cout << "3. Enter North Door to Private Chambers" << endl;
	cout << "4. Enter East Door to Library" << endl;
	cout << "5. Enter South Door to Kitchen" << endl;
	cout << "6. Enter West Door to Main Hall" << endl;
	cout << endl;
}

// Kitchen
void KitchenAction()
{
	ActionPrompt();
	cout << "1. Talk to Minion Servent" << endl;
	cout << "2. Examine ingredients" << endl;
	cout << "3. Display inventory" << endl;
	cout << "4. Return to Hoard" << endl;
	cout << endl;
}

// Library
void LibraryAction()
{
	ActionPrompt();
	cout << "1. Talk to Minion Servent" << endl;
	cout << "2. Examine books" << endl;
	cout << "3. Display inventory" << endl;
	cout << "4. Return to Hoard" << endl;
	cout << endl;
}

// Private Chambers
void PrivateChambersAction()
{
	ActionPrompt();
	cout << "1. Talk to Female Dragon" << endl;
	cout << "2. Talk to Young Dragon" << endl;
	cout << "3. Display inventory" << endl;
	cout << "4. Return to Hoard" << endl;
	cout << endl;
}

// Throne Room
void ThroneRoomAction()
{
	ActionPrompt();
	cout << "1. Confront Dragon" << endl;
	cout << "2. Leave Throne Room" << endl;
	cout << endl;
}