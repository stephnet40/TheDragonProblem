#include <iostream>
#include <string>
#include <vector>
#include "TownSquareActions.h"

using namespace std;

void ApproachBeggar()
{
	cout << endl;
	cout << "Town beggars see all kinds of things, right? Maybe he can point you in the right direction." << endl << endl;
}

void TalkToBeggar()
{
	cout << "1. Ask about rumors" << endl;
	cout << "2. Ask about strange occurrences" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl << endl;
}

void BeggarAskRumors()
{
	cout << beggar.GetName() << ": ";
	cout << "Rumors? Oh, I know all sorts of things. That lady over there? She claims her farm was destroyed by the dragon. ";
	cout << "No one actually believes that. She\'s married to some city-slicker without a lick of sense. ";
	cout << "Everyone knows he burned the fields. How? I dunno; he\'s such a failure at, well, anything really. She\'s just looking for something to cover up his screw-up. Dragon\'s an easy target." << endl << endl;

	cout << "You look at him expectantly. There has to be something useful. You\'re an adventurer looking for work! Rumors always lead to a quest! That\'s what the stories say, so it must be true." << endl << endl;

	cout << beggar.GetName() << ": ";
	cout << "Hey, don\'t look at me like that! You asked for a rumor, I gave you one. What were you expecting? We secretly have some long-lost princess with the destiny to save the world?" << endl << endl;

	cout << "You were hoping for something along those lines, but it\'s apparent he doesn\'t have anything useful as far as rumors go." << endl << endl;
}

void BeggarAskStrange()
{
	cout << beggar.GetName() << ": ";
	cout << "A friend of mine went missing about a week ago. He, uh, doesn\'t exactly like to ask for people\'s money. Not polite, like me. ";
	cout << "Probably got caught by a guard while attempting to swipe something, but it\'s weird no one came to shake me down. My friend likes to split his earnings, see, trying to show off, I\'d say. ";
	cout << "Guards know that, so whenever he get\'s caught, they come running to me. Not this time, though. If you hear something, let me know." << endl << endl;
}

int BeggarInsult(int &totalGold)
{
	int beggarPatience = 0;
	int playerChoice;

	cout << "The man stares at you for a second, clearly unimpressed." << endl << endl;

	beggarPatience = AddInfamy(beggarPatience);
	cout << beggar.GetName() << ": ";
	cout << "Ya think that\'s gonna hurt my feelings, buddy? I\'m a professional beggar, I hear fifty insults worse than that before noon. " << endl << endl;

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		beggarPatience = AddInfamy(beggarPatience);
		cout << "He continues to stare, raising an eyebrow, but doesn\'t say anything." << endl << endl;

		ContInsult(playerChoice);

		if (playerChoice == 1)
		{
			beggarPatience = AddInfamy(beggarPatience);
			cout << beggar.GetName() << ": ";
			cout << "Listen, I\'m kinda busy here with my whole beggar business. Either ask a question or get out of my way." << endl << endl;

			ContInsult(playerChoice);

			if (playerChoice == 1)
			{
				beggarPatience = AddInfamy(beggarPatience);
				if (totalGold > 25)
				{
					cout << beggar.GetName() << ": ";
					cout << "Okay, I\'m losing precious begging time because of you. You look like you got some money on you, so give me 15 gold and I don\'t stab your leg." << endl;
					totalGold -= 15;
					DisplayTotalGold(totalGold);
				}
				else
				{
					cout << beggar.GetName() << ": ";
					cout << "I\'ve been generous with my time here, considering you ain\'t exactly someone who can afford my incredibly useful information. So leave and I don\'t stab your leg." << endl << endl;
				}

				cout << "He holds out a rather sharp looking dagger. You\'d probably wonder where a beggar got something so nice looking, but you\'re not in a position to ask. ";
				cout << "You decide to back away from the beggar. Other townsfolk might be more forthcoming with information. And less stab-happy." << endl << endl;
			}
		}
	}

	return beggarPatience;
}

void LeaveBeggarConversation()
{
	cout << "He gives a lazy wave." << endl;
	cout << beggar.GetName() << ": ";
	cout << "Whatever. Enjoy your stay in town and all that junk." << endl << endl;
}

void ApproachAngryCitizen()
{
	cout << "An angry citizen means a citizen with a problem! You quickly make your way over to the seething woman, all the while trying to control the giddy grin on your face." << endl << endl;
}

void TalkToAngryCitizen()
{
	cout << "1. Ask about problem" << endl;
	cout << "2. Ask about dragon" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl;
}

void AngryAskProblem()
{
	cout << angryCitizen.GetName() << ": ";
	cout << "Problem? Oh, I have a problem. This entire worthless town is full of lazy, good-for-nothing gossiping cowards! ";
	cout << "My farm is completely destroyed and what do they do? Blame my poor husband! As if my dear Gideon would ever do such a thing." << endl << endl;

	cout << "This isn\'t exactly the kind of problem you\'re looking for, but you guess you have to start somewhere. You cross your arms, hoping you look much more interested in this drama than you are." << endl << endl;

	cout << angryCitizen.GetName() << ": ";
	cout << "Oh, Gideon might not be the best farmer out there - he\'s a city boy, he\'s doing the best he can - but he wouldn\'t destroy my family\'s legacy! ";
	cout << "It\'s that good-for-nothing dragon that showed up out of nowhere six months ago." << endl << endl;
}

void AngryAskDragon(int &violentEnd)
{
	cout << angryCitizen.GetName() << ": ";
	cout << "That blasted dragon destroyed my livelyhood! The fields are ruined and my livestock gone - eaten by a monster! And what do the guards do? Nothing! ";
	cout << "Cowards, the lot of them. They could be on their way up the mountain to kill the thing and save us all the trouble, but no! What\'s the point of guards if they won\'t protect us from monsters?" << endl;

	cout << "That\'s a valid question, you think. Why were\'t the guards doing anything? But that\'s good news for you - you can handle the dragon!" << endl << endl;

	cout << "She gives you an appraising look." << endl << endl;

	cout << angryCitizen.GetName() << ": ";
	cout << "You know, it occurs to me that you must be an adventurer. That means you\'re looking for coin. If you manage to kill that dragon, I can pay you. ";
	cout << "My husband has quite a bit of money sitting in a bank in the nearby city. Kill that monster, and I\'ll make sure you\'re rewarded." << endl << endl;

	cout << "You nod enthusiastically. Your first job! Not that you\'ll tell her about that. Killing a dragon is big time, and as a first job? ";
	cout << "Well, that\'s gotta be the best way to make a name for yourself." << endl << endl;

	violentEnd += angryCitizen.GetViolentEnd();
}

int AngryInsult()
{
	int citizenPatience = 0;
	int playerChoice;

	cout << "You\'ve clearly hit a nearve, as the woman\'s eyes look like they\'re about to pop out of her head and she begins opening and closing her mouth repeatedly. ";
	cout << "She looks a bit like a fish." << endl << endl;

	citizenPatience = AddInfamy(citizenPatience);
	cout << angryCitizen.GetName() << ": ";
	cout << "How dare you! Do you find harrassing women in distress fun? If you don\'t shut your mouth now, I will call the guards!";

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		citizenPatience = AddInfamy(citizenPatience);
		cout << "The woman now looks more like a giant tomato mixed with a fish. Huh, you\'ve never seen someone so angry before." << endl << endl;

		cout << angryCitizen.GetName() << ": ";
		cout << "Guards! Guards, over here! This delinquent is attacking me!" << endl << endl;

		cout << "Several armed guards start rushing into the square. Uh oh. You\'ve clearly bitten off more than you can chew. As the guards prepare to arrest you, ";
		cout << "you muse on your inability to keep your mouth shut. Tact was never one of your strong suits, after all." << endl << endl;
	}

	return citizenPatience;
}

void AngryLeaveConversation()
{
	cout << "You say your farewells, but the woman just continues to seeth, not paying you much mind as you leave." << endl << endl;
}

void ApproachWell(Inventory &drink)
{
	int playerChoice;
	cout << endl;
	cout << "It\'s been a long journey getting to this town. A full day! Getting some water from the town well probably couldn\'t hurt." << endl << endl;

	cout << "1. Get some water" << endl;
	cout << "2. Leave the well" << endl << endl;
	cin >> playerChoice;
	cout << endl;

	switch (playerChoice)
	{
		case 1:
			if (drink.inInventory == false)
			{
				cout << "You collect some water with the bucket hanging over the well and fill your canteen." << endl << endl;
				drink.name = "Water";
				drink.inInventory = true;
			}
			else
			{
				cout << "Your canteen is already full." << endl << endl;
			}
			break;
		case 2:
			cout << "On second thought, you\'re really not thirsty right now. You turn away from the well." << endl << endl;
			break;
		default:
			ClearInput;
			break;
	}
}