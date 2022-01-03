#include <iostream>
#include <string>
#include <vector>
#include "MarketActions.h"

using namespace std;

void TalkToConcernedCitizen()
{
	cout << "1. Ask about problem" << endl;
	cout << "2. Ask about dragon" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void ConcernAskProblem()
{
	cout << concernedCitizen.GetName() << ": ";
	cout << "It\'s my son, Jimmy. He wants to protect the town from the dragon. He\'s heard the old legend about this town and dragons, how a dragon comes to destroy the town every few hundred years. ";
	cout << "And after that farm was destroyed last week, he\'s more determined than ever to fight that thing. Jimmy is so focused on taking that thing down, but he has no formal arms training. ";
	cout << "The most he\'s done is fight imaginary creatures with a tree branch. He\'s going to get himself killed! There has to be a better way! One that doesn\'t put my Jimmy in danger!" << endl << endl;

	cout << "The only thing you can think of to help would be to take out the dragon yourself. Besides, Jimmy should leave this to the professionals, which you totally are." << endl << endl;
}

void ConcernAskDragon(int& peaceEnd)
{
	cout << "She looks at you with tentative hope." << endl << endl;

	cout << concernedCitizen.GetName() << ": ";
	cout << "All I\'ve been hearing about the dragon is how it\'s going to destroy us all, but it\'s been here for six months! The only thing it\'s done is supposedly destroy a farm, but that could have ";
	cout << "been Gideon\'s own screw up. He\'s the farm owner\'s husband and he just doesn\'t understand our way of life. Cityfolk thing they can - " << endl << endl;

	cout << "You clear your throught. This is interesting and all, but you want to know about the dragon. The woman blushes and looks at you sheepishly." << endl << endl;

	cout << concernedCitizen.GetName() << ": ";
	cout << "Sorry. The point is I don\'t think the dragon means us any harm. If it keeps coming here every few hundred years, there\'s gotta be a reason. If only we tried talking to it before attacking. ";
	cout << "This may all be a misunderstanding. Please, traveler, I don\'t have the money to pay you, but I could probably convince the townsfolk to scrounge up some kind of reward. Just please, talk to the dragon. ";
	cout << "Don\'t kill it." << endl << endl;

	cout << "An interesting idea. One you might prefer. Of course you could handle fighting a dragon (you totally could, it\'s not like you just picked up a sword for the first time a month ago - it was a month and half ago, thank you very much!), ";
	cout << "but a diplomatic solution could prevent any annoying injuries. You nod to the woman. It\'s worth a shot." << endl << endl;

	cout << concernedCitizen.GetName() << ": ";
	cout << "Oh, thank you so much! Make sure to stop by the general store. I\'ve had discussions about this with the shopkeeper. She might be able to help you out." << endl << endl;

	peaceEnd += concernedCitizen.GetPeaceEnd();
}

int ConcernInsult(int totalInfamy)
{
	int citizenPatience = 0;
	int playerChoice;

	cout << endl;
	cout << "The woman\'s face goes from worried to distressed." << endl << endl;

	cout << concernedCitizen.GetName() << ": ";
	cout << "What? Please, if I\'ve offended you in some way, I am deeply sorry. I never intended to do so. I just need someone to hear me out." << endl << endl;
	citizenPatience = AddInfamy(citizenPatience);

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		citizenPatience = AddInfamy(citizenPatience);
		cout << "Tears start to form in the woman\'s eyes." << endl << endl;
		
		cout << concernedCitizen.GetName() << ": ";
		cout << "P-please, whatever I did, I\'m s-sorry!" << endl << endl;

		ContInsult(playerChoice);

		if (playerChoice == 1)
		{
			citizenPatience = AddInfamy(citizenPatience);
			cout << "The woman doesn\'t say anything more. She bursts out into tears and walks away from you, presumably to calm down. ";
			cout << "Huh. Was it something you said?" << endl << endl;
		}
	}

	return citizenPatience;
}

void LeaveConcernConversation()
{
	cout << endl;
	cout << "She nods at you, acknowledging you leaving, but stays silent." << endl << endl;
}

void ApproachConcernedCitizen(int &peaceEnd)
{
	int playerChoice;
	int totalInfamy = 0;

	cout << endl;
	cout << "You decide to approach the worried woman. You wouldn\'t be a good adventurer if you didn\'t check on the wellbeing of someone in clear distress." << endl << endl;
	do
	{
		TalkToConcernedCitizen();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
		case 1:
			ConcernAskProblem();
			break;
		case 2:
			ConcernAskDragon(peaceEnd);
			break;
		case 3:
			totalInfamy = ConcernInsult(totalInfamy);
			if (totalInfamy > concernedCitizen.GetPatience())
			{
				playerChoice = 4;
			}
			break;
		case 4:
			LeaveConcernConversation();
			break;
		default:
			ClearInput();
			break;
		}

	} while (playerChoice != 4);
}

void StealMarketBarrel(int& barrelGold, int& totalGold, int& numLootStolen)
{
	cout << endl;
	cout << "You need the money more than these merchants. You\'re putting yourself in danger in order to protect them, after all! Besides, merchants charge ";
	cout << "ridiculous prices for their goods. Maybe if they thought about that, you wouldn\'t be taking their money. You quickly snatch the gold before anyone looks over." << endl;
	LootGold(barrelGold, totalGold);
	barrelGold = 0;
	DisplayTotalGold(totalGold);
	numLootStolen = AddInfamy(numLootStolen);
}

void LeaveMarketBarrel()
{
	cout << endl;
	cout << "These merchants worked hard to earn this money. Maybe if you talk to them, they might give you a discount. No need to take money behind their backs." << endl << endl;
}

void ExamineMarketBarrel(int &barrelGold, int &totalGold, int &numLootStolen)
{
	string playerChoice;

	if (barrelGold != 0)
	{
		cout << endl;
		cout << "You spot some barrels and crates in an out-of-the-way corner of the market. No one seems to be looking over there and the area is empty. You make your way over. ";
		cout << "You open a barrel to find fifty gold coins. Wow! Of course, you tell yourself, this is a market. Why wouldn\'t there be money here? The shopkeepers need to store it somewhere." << endl << endl;

		playerChoice = ChooseToLoot();
		if (playerChoice == "y")
		{
			StealMarketBarrel(barrelGold, totalGold, numLootStolen);
		}
		else
		{
			LeaveMarketBarrel();
		}
	}
	else
	{
		EmptyBarrel();
	}
}

void PickpocketAttempt(int &totalGold, int &numLootStolen, int &totalInfamy)
{
	if (numLootStolen < 4)
	{
		int citizenGold = 15;
		cout << endl;
		cout << "You pick an unsuspecting shopper in a rather large crowd. No one will notice you there. You walk up, pretending to be interested in whatever the stand is selling. ";
		cout << "Quickly and quietly, you reach into the man\'s pocket and grab his wallet. You linger for a moment then leave. No one noticed anything. You head to a secluded corner ";
		cout << "and open the wallet. Fifteen gold, not bad at all. You mentally pat yourself on the back for a job well done." << endl;
		LootGold(citizenGold, totalGold);
		DisplayTotalGold(totalGold);
		numLootStolen = AddInfamy(numLootStolen);
	}
	else
	{
		cout << endl;
		cout << "You look around for a potential target, but before you can pick someone, a guard calls out to you." << endl << endl;

		cout << marketGuard.GetName() << ": ";
		cout << "You, traveler!" << endl << endl;

		cout << "You turn around. You haven\'t done anything! At least, nothing anyone saw...right?" << endl << endl;

		cout << marketGuard.GetName() << ": ";
		cout << "Don\'t act all innocent. We\'ve been getting reports of missing money, and the townfolk have noticed you, newcomer, hanging around and opening barrels, grabbing whatever you can get your hands on. ";
		cout << "I see that look in your eye and I know you\'re about to try again. Well, not on my watch! You\'re coming with me." << endl << endl;

		cout << "Now you\'ve done it. As you get dragged off, you can only think of you what you could have possibly done wrong. Maybe next time you shouldn\'t steal everything in sight. ";
		cout << "Someone is bound to see you." << endl << endl;
		totalInfamy = AddInfamy(totalInfamy);
	}
}

int PickpocketCitizen(int &totalGold, int &numLootStolen)
{
	string playerChoice;
	int totalInfamy = 0;
	cout << endl;
	cout << "No one is paying attention to you, too engrossed in their shopping. This would be the perfect oppurtunity to practice your pickpocketing." << endl << endl;

	cout << "Pickpocket someone? (y/n)" << endl << endl;
	cin >> playerChoice;

	if (playerChoice == "y")
	{
		PickpocketAttempt(totalGold, numLootStolen, totalInfamy);
	}
	else
	{
		cout << endl;
		cout << "Even you aren\'t that desperate for money. You decide not to pickpocket anyone." << endl << endl;
	}

	return totalInfamy;
}