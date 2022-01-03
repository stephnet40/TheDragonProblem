#include <iostream>
#include <string>
#include <vector>
#include "EntryActions.h"

using namespace std;

extern TownGuard entryGuard = CreateEntryGuard(entryGuard);
extern TownGuard exitGuard = CreateExitGuard(exitGuard);
extern TownGuard marketGuard = CreateMarketGuard(marketGuard);
extern Citizen beggar = CreateBeggar(beggar);
extern Citizen angryCitizen = CreateAngryCitizen(angryCitizen);
extern Citizen concernedCitizen = CreateConcernedCitizen(concernedCitizen);
extern Citizen prisoner = CreatePrisoner(prisoner);
extern Citizen mayor = CreateMayor(mayor);
extern Vendor shopkeep = CreateShopkeep(shopkeep);
extern Vendor blacksmith = CreateBlacksmith(blacksmith);
extern Vendor barkeep = CreateBarkeep(barkeep);
extern Minion minionGuard = CreateMinionGuard(minionGuard);
extern Minion minionServant = CreateMinionServant(minionServant);
extern Dragon dragonLord = CreateDragonLord(dragonLord);
extern Dragon dragonWife = CreateDragonWife(dragonWife);
extern Dragon dragonChild = CreateDragonChild(dragonChild);

void ApproachGuard()
{
	cout << endl;
	cout << "You approach the guard." << endl << endl;
}

void TalkToEntryGuard()
{
	cout << "1. Ask about town" << endl;
	cout << "2. Ask about rumors" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void EntryAskTown()
{
	cout << entryGuard.GetName() << ": ";
	cout << "Oh, we\'re just a small town. We used to be a farming community, but lately we\'ve been branching out, trying to attract mercenaries and adventurers. Bring in some extra income." << endl << endl;

	cout << "Adventurers? You\'re an adventurer! Well, an adventurer hopeful. You haven\'t actually done much adventuring yet. ";
	cout << "Or at all, really. But what luck! They might even have some easy beginner problems you can solve." << endl << endl;

	cout << entryGuard.GetName() << ": ";
	cout << "Well, and there\'s the dragon." << endl << endl;

	cout << "Dragon? You look at him with wide eyes." << endl << endl;
	cout << entryGuard.GetName() << ": ";
	cout << "Oh, nothing major. It lives just north of town. Mark the Barkeep knows more." << endl << endl;
} 

void EntryAskRumors()
{
	cout << entryGuard.GetName() << ": ";
	cout << "Rumors? Now why would I tell you anything like that? ";
	cout << "I\'m no gossip, unlike that no-good, lazy bum of a guard at the north gate. Now he gives us real guards a bad name." << endl << endl;

	cout << "You\'re not sure what being an upstanding guard entails, but apparently bad-mouthing (but totally not gossiping about) your fellow guards is part of it. ";
	cout << "Perhaps talking with this guard in the north might be worth your while." << endl << endl;
}

int EntryInsult()
{
	int guardPatience = 0;
	int playerChoice;

	cout << "The guard\'s smile falls from his face, turning into a pout. He gives you wide, sad eyes. You might as well have kicked a puppy rather than insulted a grown man." << endl << endl;

	guardPatience = AddInfamy(guardPatience);
	cout << entryGuard.GetName() << ": ";
	cout << "Now hold on, stranger. That\'s no way of talking to someone you just met. I know you must have travelled a long ways and you must be exhausted, ";
	cout << "but there\'s no need to take it out on others. The rest of the town folk might not be so understanding. ";
	cout << "He\'s giving you a look of disappointment." << endl << endl;

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		guardPatience = AddInfamy(guardPatience);
		cout << "He frowns." << endl << endl;

		cout << entryGuard.GetName() << ": ";
		cout << "Please stop. Last warning. We don\'t need someone here looking for a fight." << endl << endl;

		ContInsult(playerChoice);

		if (playerChoice == 1)
		{
			guardPatience = AddInfamy(guardPatience);
			cout << "Any lighthearted expression left on his face disappears." << endl << endl;

			cout << entryGuard.GetName() << ": ";
			cout << "That\'s it, leave. Get out of our town. We don\'t need such rude behavior here." << endl << endl;

			cout << "He points his spear at you. You know when you\'re not wanted. You turn and leave. Maybe the next town will be more welcoming." << endl << endl;
		}
	}

	return guardPatience;
}

void LeaveEntryConversation()
{
	cout << endl;
	cout << entryGuard.GetName() << ": ";
	cout << "Alright! Enjoy your stay!" << endl << endl;
}

void StealEntryBarrel(int &barrelGold, int &totalGold, int &numLootStolen)
{
	cout << endl;
	cout << "If this money was so important, then no one would just leave it out in the open like this. Just sitting in a barrel. ";
	cout << "That\'s closed. With a bunch of cargo that looks ready to transport. It\'s just begging to be taken! You grab the gold." << endl;

	LootGold(barrelGold, totalGold);
	barrelGold = 0;
	DisplayTotalGold(totalGold);
	numLootStolen = AddInfamy(numLootStolen);
}

void LeaveEntryBarrel()
{
	cout << endl;
	cout << "It\'s clear that this barrel is part of a merchant\'s or farmer\'s haul. They must have needed to leave it for some reason or another. ";
	cout << "Best not take the gold, even if your wallet feels noticeably light as you turn away from the barrel." << endl << endl;
}

void ExamineEntryBarrel(int &barrelGold, int &totalGold, int &numLootStolen)
{
	string playerChoice;

	if (barrelGold != 0)
	{
		cout << endl;
		cout << "You look at the barrels and crates located near the town entrance. Adventurers always look through things like that, right? ";
		cout << "That\ns what the stories say, at least. You peek inside one of the barrels. Jackpot! Ten gold coins just laying there for the taking." << endl << endl;

		playerChoice = ChooseToLoot();
		if (playerChoice == "y")
		{
			StealEntryBarrel(barrelGold, totalGold, numLootStolen);
		}
		else
		{
			LeaveEntryBarrel();
		}
	}
	else
	{
		EmptyBarrel();
	}
}

void LeaveTown()
{
	cout << endl;
	cout << "Staring at the buildings and people milling around town, you start to feel overwhelmed by the unknown that lays ahead of you. ";
	cout << "Maybe adventuring isn\'t for you. You turn back south and leave town, deciding to go home. ";
	cout << "Not like this town was in much need of help, anyways." << endl << endl;
}