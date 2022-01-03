#include <iostream>
#include <string>
#include <vector>
#include "ExitActions.h"

using namespace std;

void TalkToExitGuard()
{
	cout << "1. Ask about town" << endl;
	cout << "2. Ask about dragon" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void ExitAskTown()
{
	cout << "The guard looks bored, so he has to have some good info about the town. It\'s not like he\'s got anything better to do than people watch." << endl << endl;

	cout << exitGuard.GetName() << ": ";
	cout << "Sure, I know things. The mayor decided to attract adventurers like you to town. He says it\'s to expand the economy, but everyone knows he\'s just looking for some sucker to kill the dragon. ";
	cout << "Wants to be known as the guy who solved our dragon problem. Then there\'s Camilla and Gideon, who\'s farm was destroyed. Camilla insists it was the dragon, everyone else says Gideon. ";
	cout << "Then there\'s Elena and her son Jimmy, who wants to take on the dragon himself. Elena insists the dragon can be reasoned with, though. She\'s not all there, though. Or worry has completely destroyed her mind. ";
	cout << "How can a dragon be even be reasoned with? Can they even talk?" << endl << endl;

	cout << "Sounds like all the rumors lead to the dragon. Take care of the dragon problem and you\'ll have a grateful town to spread word of your skills." << endl << endl;
}

void ExitAskDragon()
{
	cout << "He blinks once, twice, before answering." << endl << endl;

	cout << exitGuard.GetName() << ": ";
	cout << "The dragon? Just showed up one day. I guess there\'s some kind of legend, but meh, I dunno much. It\'s here, though." << endl << endl;

	cout << "You were hoping for something more. You prompt him to go on, but he just stares at you. Doesn\'t seem like you\'ll be getting anything else out of him." << endl << endl;
}

int ExitInsult()
{
	int guardPatience = 0;
	int playerChoice;

	cout << "The corners of his mouth lift ever so slightly. He still looks bored, but now it\'s a slightly amused bored." << endl << endl;
	
	cout << exitGuard.GetName() << ": ";
	cout << "Heh, you\'re kinda funny. Thanks for the entertainment." << endl << endl;

	cout << "That...wasn\'t the reaction you were expecting." << endl << endl;
	guardPatience = AddInfamy(guardPatience);

	ContInsult(playerChoice);
	
	if (playerChoice == 1)
	{
		guardPatience = AddInfamy(guardPatience);
		cout << "His sort-of-smile grows a little more, but he doesn\'t say anything." << endl << endl;

		ContInsult(playerChoice);
		if (playerChoice == 1)
		{
			guardPatience = AddInfamy(guardPatience);
			cout << "He tilts his head, his full attention on you." << endl << endl;

			ContInsult(playerChoice);
			if (playerChoice == 1)
			{
				guardPatience = AddInfamy(guardPatience);
				cout << "There has to be something he reacts to! No one is this stoic. You\'re not giving up!" << endl << endl;

				ContInsult(playerChoice);
				if (playerChoice == 1)
				{
					guardPatience = AddInfamy(guardPatience);
					cout << "Still nothing. Does this man even understand what\'s going on?" << endl << endl;

					ContInsult(playerChoice);
					if (playerChoice == 1)
					{
						guardPatience = AddInfamy(guardPatience);
						cout << "Ugh! That is it! You\'re done. How can anyone just stand there silent? You turn around and march straight out of town. ";
						cout << "Clearly you have some work to do on your witty insults before becoming an official adventurer." << endl << endl;
					}
				}
			}
		}
	}

	return guardPatience;
}

void LeaveExitConversation()
{
	cout << "The guard yawns as you leave, giving you not even a half-hearted wave." << endl << endl;
}

void ApproachGuard(int &totalInfamy)
{
	int playerChoice;
	totalInfamy = 0;

	cout << "You decide to walk to up to the bored guard. He clearly has time to talk to you." << endl << endl;

	do
	{
		TalkToExitGuard();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
			case 1:
				ExitAskTown();
				break;
			case 2:
				ExitAskDragon();
				break;
			case 3:
				totalInfamy = ExitInsult();
				if (totalInfamy > exitGuard.GetPatience())
				{
					playerChoice = 4;
				}
				break;
			case 4:
				LeaveExitConversation();
				break;
			default:
				ClearInput();
		}
	} while (playerChoice != 4);
}