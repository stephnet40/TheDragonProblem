#include <iostream>
#include <string>
#include <vector>
#include "VillageActions.h"

using namespace std;

void ApproachMayor()
{
	cout << endl;
	cout << "You approach the rotund man. He seems cheerful, almost unbearably so." << endl << endl;
}

void TalkToMayor()
{
	cout << "1. Ask about dragon" << endl;
	cout << "2. Ask about town problems" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void MayorAskDragon()
{
	cout << "Everywhere you go in this town, you\'ve been hearing about some dragon. The mayor has to know something." << endl << endl;

	cout << mayor.GetName() << ": ";
	cout << "Ah, I see you\'ve been made aware of our little dragon problem. Well, I guess a problem is one way to put it. For as long as our town has existed, ";
	cout << "going back to when it was just a tiny village just starting up, the moutain over us has been home to a dragon\'s lair. Story goes that every few generations, ";
	cout << "a dragon appears to wreck havoc amoung our community, only leaving after fifty years of rampaging." << endl << endl;

	cout << "Interesting. A town besieged by a dragon\'s curse! Just what you were looking for!" << endl << endl;

	cout << mayor.GetName() << ": ";
	cout << "Those tales seem to be exagerrated, though, based on what has happened since the dragon showed up six months ago. When that beast\'s shadow crossed our dear town, ";
	cout << "we thought our fortunes to be doomed. But all that\'s happened is Gideon and Camilla\'s farm being ransacked. The some fields were burned and a cow was taken. ";
	cout << "Hardly the doom and gloom the legends state. But fifty years is a long time; maybe the dragon is biding its time." << endl << endl;

}

void MayorAskProblems()
{
	cout << mayor.GetName() << ": ";
	cout << "Hm? Problems? You some wandering mercenary?" << endl << endl;

	cout << "Is that another word for adventurer? You think so, so you nod your head enthusiastically. The mayor lets out a hearty laugh." << endl << endl;

	cout << mayor.GetName() << ": ";
	cout << "That's wonderful! Looks like our branching out to the hero demographic is paying off! Well, there\'s the problem with the destroyed farm. Talk with Camilla ";
	cout << "in the town square. She\'s the scowling woman. You might be able to learn something useful over in the market, too." << endl << endl;
}

int MayorInsult(int &totalGold)
{
	int mayorPatience = 0;
	int playerChoice;

	cout << mayor.GetName() << ": ";
	cout << "Oh, what was that now, traveler?" << endl << endl;
	mayorPatience = AddInfamy(mayorPatience);

	cout << "The man has a predatory gleam in his eye. You gulp. Don\'t show fear!" << endl << endl;

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		mayorPatience = AddInfamy(mayorPatience);

		cout << mayor.GetName() << ": ";
		cout << "That\'s what I thought. It\'s unfortunate our first encounter had to go this way. Now I know you don\'t want to get in trouble with the law, ";

		if (totalGold >= 15)
		{
			cout << "so if you give me, say, ten gold I can look the other way and not tell the guards about this little incident." << endl << endl;

			cout << "Something about this man makes you think this isn\'t an ideal threat. You give him the money and quickly leave." << endl << endl;
			totalGold -= 10;
			DisplayTotalGold(totalGold);
		}
		else
		{
			cout << "so if you don\'t want my guards arresting you on the spot, I suggest you turn tail and leave my sight." << endl << endl;

			cout << "Something about this man makes you think this isn\'t an ideal threat. You quickly leave." << endl << endl;
		}
	}

	return mayorPatience;
}

void LeaveMayorConversation()
{
	cout << mayor.GetName() << ": ";
	cout << "Enjoy your stay, traveler!" << endl << endl;
}

void LookAtHome()
{
	cout << "1. Steal from a home" << endl;
	cout << "2. Step away from homes" << endl << endl;
}

int StealFromHome(int &totalGold, int &numLootStolen)
{
	int caughtStealing = 0;
	int playerChoice;
	int rightHouseGold = 50;
	bool alreadyStole = false;

	cout << "There are couple of nice, rich-looking homes. Some adventurers steal to properly equip themselves, that\'s what you\'ve heard. Most people don\'t mind, that\'s just something ";
	cout << "you expect when adventurers show up." << endl << endl;

	do {
		cout << "1. Steal from house on right" << endl;
		cout << "2. Steal from house on left" << endl;
		cout << "3. Walk away" << endl << endl;
		cin >> playerChoice;
		cout << endl;

		if (playerChoice == 1)
		{
			if (alreadyStole == false)
			{
				cout << "You circle around to the back of the right house, out of sight of the people milling around the neighborhood. You jiggle the doorknob to the backdoor. It swings open. ";
				cout << "You guess no one locks their doors in this town. It doesn\'t take long to find a chest filled with gold. Perfect! You help yourself, taking 50 gold." << endl;
				caughtStealing = 0;
				totalGold += 50;
				numLootStolen = AddInfamy(numLootStolen);
				alreadyStole = true;
				DisplayTotalGold(totalGold);
			}
			else
			{
				cout << "You\'ve already taken what you can from this home." << endl << endl;
			}
		}
		else if (playerChoice == 2)
		{
			cout << "You circle around to the back of the left house, out of sight of the people milling around the neighborhood. You jiggle the doorknob to the backdoor. It swings open. ";
			cout << "You guess no one locks their doors in this town. As soon as you step inside, however, you realize your mistake. A startled voice yells out. Before you know it, you\'re ";
			cout << "pinned on the ground, guards flooding into the home. Maybe you should have check if anyone was home before attempting theft." << endl << endl;
			caughtStealing = 1;
		}
		else
		{
			cout << "You turn away from the homes. Best not try your luck. You\'re still a beginner adventurer after all." << endl << endl;
		}
	} while (playerChoice == 1);

	return caughtStealing;
}

void LeaveHome()
{
	cout << "You turn away from the homes." << endl << endl;
}

void ApproachHome(int &caughtStealing, int &totalGold, int &numLootStolen)
{
	int playerChoice;
	caughtStealing = 0;
	cout << endl;
	cout << "You decide to take a closer look at the homes. It really is a nice village. The houses look like something out of a fairytale. Must be nice to live in such a place." << endl << endl;

	do
	{
		LookAtHome();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
		case 1:
			caughtStealing = StealFromHome(totalGold, numLootStolen);
			if (caughtStealing == 1)
			{
				playerChoice = 2;
			}
			break;
		case 2:
			LeaveHome();
			break;
		default:
			ClearInput();
			break;
		}
	} while (playerChoice != 2);
}

void StealHomeBarrel(int &barrelGold, int &totalGold, int &numLootStolen)
{
	cout << endl;
	cout << "You\'re going to be helping this town. This would just be part of your payment, right? Making up your mind, you take the gold." << endl;
	LootGold(barrelGold, totalGold);
	barrelGold = 0;
	DisplayTotalGold(totalGold);
	numLootStolen = AddInfamy(numLootStolen);
}

void LeaveHomeBarrel()
{
	cout << endl;
	cout << "It doesn\'t feel right, just taking someone\'s money like this. You could at least ask, but no one\'s around. With a heavy sigh, you leave the barrel alone." << endl << endl;
} 

void ExamineHomeBarrel(int &barrelGold, int &totalGold, int &numLootStolen)
{
	string playerChoice;

	if (barrelGold != 0)
	{
		cout << "Some barrels and crates are sitting in front of one of the homes. You take a look inside one of the barrels to find fiftee gold. ";
		cout << "Might be someone\'s savings, but you also need the money." << endl << endl;

		playerChoice = ChooseToLoot();
		if (playerChoice == "y")
		{
			StealHomeBarrel(barrelGold, totalGold, numLootStolen);
		}
		else
		{
			LeaveHomeBarrel();
		}
	}
	else
	{
		EmptyBarrel();
	}

}