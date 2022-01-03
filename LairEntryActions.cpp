#include <iostream>
#include <string>
#include <vector>
#include "LairEntryActions.h"

using namespace std;

void LairEntryOptions()
{
	cout << "1. Fight your way in" << endl;
	cout << "2. Sneak passed guard" << endl; 
	cout << "3. Do nothing" << endl << endl;
}

void FightGuard(string &encounterResult)
{
	cout << "You run up to the guard, ready to fight. He draws his weapon." << endl << endl;

	if (weapon.inInventory == true && weapon.name == "Steel Sword")
	{
		cout << "You pull out your sword. This is it, your first battle. Even though you really don\'t know what you\'re doing, you manage to get in a strong blow to the guard\'s head. ";
		cout << "He falls to the ground unconcious. At least, you\'re pretty sure he\'s unconcious. Can green goblin minions take blows to the head and be okay? ";
		cout << "You decide not to think about it too hard and head inside the lair." << endl << endl;
		encounterResult = "success";
	}
	else if (weapon.inInventory == true && weapon.name == "Wooden Sword")
	{
		cout << "You pull out your sword. The guard laughs at you and wastes no time breaking your sword. You quickly drop what remains of your weapon and race back to town." << endl << endl;
		encounterResult = "return to town";
		weapon.inInventory = false;
		weapon.name = "";
	}
	else
	{
		cout << "As you reach for a weapon, you realize you completely forgot to get one in town. Oh no. The guard manages to beat you down and drag you off into the dungeons, where you will spend who knows how long rotting away." << endl << endl;
		encounterResult = "game over";
	}
}

void SneakPass(string &encounterResult)
{
	if (map.inInventory == true)
	{
		cout << "You pull out the map the barkeeper gave you. With it, you manage to find a path into the main hall of the lair without being spotted by the guard." << endl << endl;
		encounterResult = "success";
	}
	else
	{
		cout << "You navigate the best you can, but it doesn\'t take long for the guard to spot. He quickly runs over and ties you up, dragging you to the dungeons to rot." << endl << endl;
		encounterResult = "game over";
	}
}

void DoNothing(string &encounterResult)
{
	cout << "You\'re not sure if you can make your way passed the guard. You step away to better prepare." << endl << endl;
	encounterResult = "return to town";
}

void EncounterEntryMinion(string &encounterResult)
{
	int playerChoice;
	cout << endl;
	cout << "You need to decide how to deal with the guard. Once you do and manage to get into the lair, you won\'t be able to go back to town until you\'ve dealt with the dragon." << endl << endl;

	LairEntryOptions();
	do
	{
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				FightGuard(encounterResult);
				break;
			case 2:
				SneakPass(encounterResult);
				break;
			case 3:
				DoNothing(encounterResult);
				break;
			default:
				ClearInput();
				break;
		}

	} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
}
