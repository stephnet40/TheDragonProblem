#include <iostream>
#include <string>
#include <vector>
#include "DungeonActions.h"

using namespace std;

void TalkToJailGuard()
{
	cout << "1. Fight guard" << endl;
	cout << "2. Bribe guard" << endl;
	cout << "3. Negotiate with guard" << endl << endl;
}

void FightGuard(int &totalInfamy, bool &foughtGuard)
{
	cout << "You get in a fighting stance." << endl << endl;

	cout << minionGuard.GetName() << ": ";
	cout << "You wanna fight? Let\'s do this, then!" << endl << endl;

	if (weapon.inInventory == true && (weapon.name == "Steel Sword" || weapon.name == "Dragon Slayer"))
	{
		cout << "Pulling out your sword, you lunge and attack. The fight is short and intense, but you managed to win. The guard lays at your feet, unconcious. Yeah, you\'ll go with that. ";
		cout << "Crouching down, you search the guard\'s pockets and quickly find the key to the cell." << endl << endl;
		cellKey.inInventory = true;
		cellKey.name = "Cell Key";
		foughtGuard = true;
	}
	else if (weapon.inInventory == true && weapon.name == "Wooden Sword")
	{
		cout << "You pull out your sword, but before you can even move, the guard breaks your weapon in two. You toss the broken hilt and stand up straight, hands behind your back and an innocent smile on your face. ";
		cout << "Maybe he won\'t do anything bad if you act like you didn\'t mean to attack. But nope, he grabs you by the shirt and tosses you into an empty cell, locking it. Now you\'re stuck here, all because you were a cheapskate over a weapon." << endl << endl;
		totalInfamy = AddInfamy(totalInfamy);
	}
	else
	{
		cout << "You go to pull out a weapon, but quickly realize you never grabbed one in the first place. The guard knocks you off your feet, picks you up, and throws you into a cell to let you rot." << endl << endl;
		totalInfamy = AddInfamy(totalInfamy);
	}
}

void BribeGuard(int &totalInfamy, bool &bribedGuard)
{
	int playerChoice;
	do
	{
		cout << "Everyone can be bribed, you think to yourself. That\'s the best way to do this." << endl << endl;

		cout << "1. Offer money" << endl;
		cout << "2. Offer food" << endl << endl;

		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
		case 1:
			cout << "The guard looks insulted." << endl << endl;
			cout << minionGuard.GetName() << ": ";
			cout << "Money? What the hell do I need money for? You know how much I get paid here? How about I throw you in a cell for attempted bribery, huh?" << endl << endl;

			cout << "Faster than you can process what he said, he throws you into an empty cell and locks it. Clearly these guards have more integrity than you." << endl << endl;
			totalInfamy = AddInfamy(totalInfamy);
			break;
		case 2:
			cout << "You hear the guard\'s stomach growl. He glares out you, daring you to say something. So you do - you offer him food." << endl << endl;
			if (food.inInventory == true)
			{
				cout << "You pull out the jerky you bought in town. The man\'s eyes light up and he grabs the offering." << endl << endl;
				cout << minionGuard.GetName() << ": ";
				cout << "Well, I suppose I can look the other way while you take a look around. No funny business, now." << endl << endl;

				cout << "You smile to yourself as you watch him devour the jerky. Who would have expected food to be the answer?" << endl << endl;
			}
			else
			{
				cout << "You smile at him a few seconds as he waits expectantly. When you don\'t proffer up anything, his expression morphs into one of anger." << endl << endl;

				cout << minionGuard.GetName() << ": ";
				cout << "How dare you attempt to bribe me, a loyal guard of the Dragon lord! Even if you did have food, I wouldn\'t accept it, no matter how hunger!" << endl << endl;

				cout << "You\'re not sure how true that is, but you can\'t linger on that thought for long. The guard quickly throws you into a cell, locking it behind you. ";
				cout << "Apparently, falsly offering food to a hungry man is a bad idea." << endl << endl;
				totalInfamy = AddInfamy(totalInfamy);
			}
			bribedGuard = true;
			break;
		default:
			ClearInput;
			break;
		}
	} while (playerChoice != 1 && playerChoice != 2);
}

void NegotiateGuard(int &totalInfamy)
{
	cout << minionGuard.GetName() << ": ";
	cout << "I\'m here to guard prisoners, not negotiate. You clearly aren\'t supposed to be here, though. But if you want to spend time here, how \'bout in this cell here?" << endl << endl;

	cout << "Before you can realize what\'s happening, you find yourself in a locked cell. Clearly this man has zero patience and because of that, you\'re stuck in a dingy jail cell, possibly forever." << endl << endl;
	totalInfamy = AddInfamy(totalInfamy);
}

void EncounterDungeonGuard(int &totalInfamy, bool &foughtGuard, bool &bribedGuard)
{
	totalInfamy = 0;
	int playerChoice;
	cout << "You\'d rather not be bothered while you\'re down here, so you confront the guard to let you explore in peace." << endl << endl;

	do
	{
		TalkToJailGuard();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				FightGuard(totalInfamy, foughtGuard);
				break;
			case 2:
				BribeGuard(totalInfamy, bribedGuard);
				break;
			case 3:
				NegotiateGuard(totalInfamy);
				break;
			default:
				ClearInput();
				break;
		}
	} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
}

void AskLockUp()
{
	cout << prisoner.GetName() << ": " << endl;
	cout << "I\'m a thief, of course. A dragon\'s hoard is the ultimate challenge. Too much of one for me, I guess. I have a friend in town, a beggar. ";
	cout << "He always said I was too ambitious for my own good. Guess he was right. You know, you look like you\'re one of those do-gooder types. ";
	cout << "Think you could help me get out of here? I\'d really appreciate it." << endl << endl;

	cout << "This man might be a thief, but no one deserves to be trapped in a dragon\'s lair. You agree to try and help him out." << endl << endl;
}

void AskPrisonerDragon()
{
	cout << prisoner.GetName() << ": " << endl;
	cout << "Frankly, I don\'t know much outside the town legend about the dragon attacking every few hundred years. I just broke in to for the hoard. Didn\'t even get to see it before I got caught. ";
	cout << "If it weren\'t for everyone talking obsessively about their Dragon lord, I\'d question if the dragon was even real. But the guards and servants are obsessed with protecting their master. ";
	cout << "No one\'s allowed to just see him, or the hoard for that matter. They really care about the hoard, actually." << endl << endl;
}

void PrisonerInsult()
{
	cout << prisoner.GetName() << ": ";
	cout << "Ha ha, you\'re very funny. But seriously, what are going to accomplish with that? I\'m in a cell, the guards insult me all the time. That guy isn\'t gonna care. Why bother?" << endl << endl;

	cout << "He\'s got a point. You decide to move on to something more productive." << endl << endl;
}

void LeavePrisonerConversation()
{
	cout << prisoner.GetName() << ": ";
	cout << "Bye. I\'ll just be right here." << endl << endl;
}

void TalkToPrisoner()
{
	cout << endl;
	cout << "1. Ask about imprisonment";
	cout << "2. Ask about dragon";
	cout << "3. Insult";
	cout << "4. Leave conversation" << endl << endl;
}

void ApproachPrisoner()
{
	int playerChoice;

	do
	{
		TalkToPrisoner();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
		case 1:
			AskLockUp();
			break;
		case 2:
			AskPrisonerDragon();
			break;
		case 3:
			PrisonerInsult();
			break;
		case 4: 
			LeavePrisonerConversation();
			break;
		default:
			ClearInput();
			break;
		}
	} while (playerChoice != 4);
}

void CellUnlocked()
{
	cout << "You stand by the cell door. The former prisoner looks at you, still looking through crates." << endl << endl;
	cout << prisoner.GetName() << ": ";
	cout << "I\'m still looking for my stuff. Go on ahead, do whatever you need to." << endl << endl;
}

void BribeGuardAgain(int &totalInfamy, bool &unlocked)
{
	int playerChoice;
	cout << "The guard might unlock the cell if you bribe him again." << endl << endl;
	do
	{
		cout << "1. Offer money" << endl;
		cout << "2. Offer food" << endl;
		cout << "3. Offer drink" << endl << endl;
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
		case 1:
			cout << "The guard stands up straight and glares at you." << endl << endl;
			cout << minionGuard.GetName() << ": ";
			cout << "Excuse me? You think because I let you wonder around down after you gave me food, you can just bribe me? Well, think again." << endl << endl;

			cout << "He grabs you and tosses you into an empty cell, locking it. It looks like you might be in there a while." << endl << endl;
			totalInfamy = AddInfamy(totalInfamy);
			break;
		case 2:
			cout << "The guard blushes slightly before sputtering out some angry words." << endl << endl;
			cout << minionGuard.GetName() << ": ";
			cout << "Hey, was that jerky just a bribe? I thought you were nice, but clearly not. You know what we do to those who try to get their way through bribery? Lock \'em up for life." << endl << endl;

			cout << "He shoves you into a vacant cell, slamming the door shut. Who knew bribery had such a harsh punishment?" << endl << endl;
			totalInfamy = AddInfamy(totalInfamy);
			break;
		case 3:
			cout << "You hold out your full canteen. Who would be mean to someone who offered water?" << endl << endl;
			cout << minionGuard.GetName() << ": ";
			cout << "Oh, well, thanks. That jerky did make me thirsty. This\'ll really help. I guess I can open that cell in exchange." << endl << endl;

			cout << "He unlocks the cell door after taking a long gulp of water. Thankfully, he only drank half of it. The prisoner grins at you from the now-open cell door." << endl << endl;

			cout << prisoner.GetName() << ": ";
			cout << "Thanks, pal! I\'m just gonna take a look around, get my stuff. You do whatever you need to do, alright?" << endl << endl;
			cout << "He immediately starts rummaging through the boxes and barrels spread across the dungeon. Looks like you\'ll be traveling the lair alone." << endl << endl;
			unlocked = true;
			break;
		default:
			ClearInput();
			break;
		}
	} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
}

void UnlockCell(int &totalInfamy, bool foughtGuard, bool bribedGuard, bool &unlocked)
{
	totalInfamy = 0;

	if (foughtGuard == true)
	{
		cout << "Using the guard\'s key, you unlock the cell, letting the prisoner out." << endl << endl;

		cout << prisoner.GetName() << ": ";
		cout << "Thanks, bud. I gotta search for all my stuff, so don\'t wait up for me." << endl << endl;

		cout << "He begins going through the various boxes and barrels dotted throughout the dungeon. You\'ve clearly been dismissed. It seems you have nothing left to do down here." << endl << endl;
	}
	else if (bribedGuard == true)
	{
		BribeGuardAgain(totalInfamy, unlocked);
	}
	else
	{
		cout << "You dare not get any closer to the lock while the guard is staring at you. Maybe you should talk with him first." << endl << endl;
	}

}