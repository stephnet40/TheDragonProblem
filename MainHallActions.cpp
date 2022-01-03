#include <iostream>
#include <string>
#include <vector>
#include "MainHallActions.h"

using namespace std;

void TellGoodLie(bool &dealtWithServant)
{
	cout << "You manage to come up with a clever lie, not stuttering over a single word. You\'re simply looking for a job and hey, dragons pay well, right?" << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "Well, you\'ve come to the right place! The Dragon lord doesn\'t conduct the interviews, that would be Ms. Sarah. Take the east door to the servant quarters." << endl << endl;

	cout << "She leaves you to resume her duties. Well, that was easy." << endl << endl;

	dealtWithServant = true;
}

void TellBadLie(int &totalInfamy)
{
	cout << "Her eyes narrow as you stumble over your lie. You don\'t even finish before you realize she\'s not buying it." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "Guards! Guards! We have an intruder!";

	if (map.inInventory == true)
	{
		cout << "As you run away, you\'re realize it is a good thing you managed to study the map before entering the lair. You manage to evade the guards, but the only way to do that was to leave the lair entirely. ";
		cout << "You made it out to safety, but you have no desire to return. This particular adventure isn\'t worth it." << endl << endl;
	}
	else
	{
		cout << "You try to escape to guards, but you can\'t find your way through the lair. The guards catch you, throwing you in the dungeon, possibly forever." << endl << endl;
	}

	totalInfamy = AddInfamy(totalInfamy);
}

void TellTruth(int &totalInfamy)
{
	cout << "Your mother always said honesty is the best policy, so that\'s what you choose. The servant doesn\'t seem to appreciate it, though, as she tenses up. She makes a motion with her hand as she speaks." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "When we get adventurers arriving, wanting to see the Dragon lord, all they want to do is kill him. Sorry, but that\'s not happening." << endl << endl;

	cout << "That hand motion was actually her signaling a guard. A strong arm grabs you from behind, dragging you off to the dungeons. Maybe honesty is always the best policy, Mom." << endl << endl;

	totalInfamy = AddInfamy(totalInfamy);
}

void EncounterMainServant(int &totalInfamy, bool &dealtWithServant)
{
	totalInfamy = 0;
	int playerChoice;

	cout << endl;
	if (dealtWithServant == false)
	{
		cout << "You decide to talk with the servant and convince her not to call any guards." << endl << endl;

		cout << "1. Lie - You\'re looking for employment" << endl;
		cout << "2. Lie - You\'re a safety inspector" << endl;
		cout << "3. Tell the truth" << endl << endl;

		do
		{
			cin >> playerChoice;
			cout << endl;
			switch (playerChoice)
			{
			case 1:
				TellGoodLie(dealtWithServant);
				break;
			case 2:
				TellBadLie(totalInfamy);
				break;
			case 3:
				TellTruth(totalInfamy);
				break;
			default:
				ClearInput();
				break;
			}
		} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
	}
	else
	{
		cout << "The servant waves at you and reminds you to see Ms. Sarah." << endl << endl;
	}
}

void OpenThroneRoom(Inventory throneKey)
{
	cout << endl;
	if (throneKey.inInventory == true)
	{
		cout << "You take out the key to the throne room and unlock to door. Time to face this dragon." << endl << endl;
	}
	else
	{
		cout << "The door is locked. You need to find a key first." << endl << endl;
	}
}

void OpenHoard(Inventory hoardKey, bool &unlocked)
{
	cout << endl;
	if (hoardKey.inInventory == true)
	{
		cout << "You take out the key the shopkeeper gave you. It\'s a perfect fit. The door unlocks." << endl << endl;
		unlocked = true;
	}
	else
	{
		cout << "The door is locked." << endl << endl;
	}
}