#include <iostream>
#include <string>
#include <vector>
#include "SideHallActions.h"

using namespace std;

void TalkToSideServant()
{
	cout << "1. Ask about working with dragon" << endl;
	cout << "2. Reveal truth about why you\'re there" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void AskDragonWork()
{
	cout << "The servant smiles with pride. Clearly he enjoys his job." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "Working for my lord is a fulfilling experience. He is a fair lord who rules over the castle..." << endl << endl;

	cout << "You quickly regret asking as the servant goes on, gushing over his work and the dragon. You tune him out, feigning interest until he finishes five minutes later." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "To work here is an honor and a privilege. Oh my, my apologizes, I didn\'t mean to take up so much of your time. Was there anything else you needed?" << endl << endl;
}

int RevealTruth()
{
	int totalInfamy = 0;

	cout << "The man stands up straighter, looking down his nose at you." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "Well, I must thank you for your honesty. Now I can deal with you free of guilt. Guards! Throw this intruder in the dungeon." << endl << endl;

	cout << "You don\'t know where they came from, but three guards swarm you, dragging you off into the dungeon to live the rest of your days." << endl << endl;

	totalInfamy = minionServant.GetPatience() + 1; // allows a single gameover check in TheDragonProblem.cpp by using the same condition as the insult gameover

	return totalInfamy;
}

int SideInsult()
{
	int servantPatience = 0;
	int playerChoice;

	cout << "The man\'s lips curl up in distaste." << endl << endl;
	cout << minionServant.GetName() << ": ";
	cout << "How vulgar. I suggest you think carefully on what you say next." << endl << endl;
	servantPatience = AddInfamy(servantPatience);

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		servantPatience = AddInfamy(servantPatience);
		cout << "The man looks at you as if you were less than an insect." << endl << endl;
		cout << minionServant.GetName() << ": ";
		cout << "I will tell you now, we do not tolerate such behavior here." << endl << endl;

		ContInsult(playerChoice);

		if (playerChoice == 1)
		{
			servantPatience = AddInfamy(servantPatience);
			cout << minionServant.GetName() << ": ";
			cout << "Guards! Arrest this vulgar delinquint at once!" << endl << endl;

			cout << "Several guards surround you, dragging you off to the dungeon. At least you got a laugh before being imprisoned for life." << endl << endl;
		}
	}

	return servantPatience;
}

void LeaveSideConversation()
{
	cout << "You thank him for his time." << endl << endl;
	cout << minionServant.GetName() << ": ";
	cout << "Of course. I will be available if you wish to talk again." << endl << endl;
}

void EncounterSideServant(int &totalInfamy)
{
	int playerChoice;

	cout << endl;
	cout << "This servant might know something. You walk up to him." << endl << endl;

	do
	{
		TalkToSideServant();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				AskDragonWork();
				break;
			case 2:
				totalInfamy = RevealTruth();
				playerChoice = 4;
				break;
			case 3: 
				totalInfamy = SideInsult();
				if (totalInfamy > minionServant.GetPatience())
				{
					playerChoice = 4;
				}
				break;
			case 4:
				LeaveSideConversation();
				break;
			default:
				break;
		}
	} while (playerChoice != 4);	
}

void OpenArmory(Inventory armoryKey, bool &unlocked)
{
	cout << endl;
	if (armoryKey.inInventory == true)
	{
		cout << "The key the blacksmith gave you works perfectly. You unlock the door and enter." << endl << endl;
		unlocked = true;
	}
	else
	{
		cout << "The door is locked" << endl << endl;
	}
}