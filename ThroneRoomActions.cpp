#include <iostream>
#include <string>
#include <vector>
#include "ThroneRoomActions.h"

using namespace std;

string NegotiateDragon()
{
	string endResult;

	if (dragonWife.GetSpokeWith() == true)
	{
		cout << "According to his wife, the dragon is just a big ol\' softie. He\'ll listen, right? As you approach, he speaks in a booming voice." << endl << endl;

		cout << dragonLord.GetName() << ": ";
		cout << "I had heard a stranger had made their way into my home. You even managed to make it to my family\'s private dwelling! Considering you are still alive, my mate must approve of you. ";
		cout << "What can I do for you, stranger?" << endl << endl;

		cout << "You explain what\'s been going on in town and what the townsfolk want you to do. Personally, you hope you can settle everything peacefully." << endl << endl;

		cout << dragonLord.GetName() << ": ";
		cout << "Truely? I had no idea my family\'s presence had caused so much concern. Thank you for bringing it to my attention. You seem reasonable and helpful to have around. ";
		cout << "Do you mind working as an ambassador of sorts between my household and the town? Having a human to help speak for me would be a massive help in calming the townsfolk\'s worry." << endl << endl;

		cout << "It\'s not what you set out to do when you left you, but you agree. Thanks to your efforts, the town and dragon were able to come to an understanding. ";
		cout << "In fact, now the town views the dragon as a town guardian of sorts! And you are happily living in the castle, working as an abassador and becoming an unofficial member of the dragon family." << endl << endl;
		endResult = "peace end";
	}
	else
	{
		cout << "You really hope the concerned woman in town was right and all of this was just a misunderstanding. You carefully approach the dragon, trying to seem unthreatening." << endl << endl;

		cout << dragonLord.GetName() << ": ";
		cout << "I had heard a stranger had made their way into my home. Who are you? Why have you trespassed?" << endl << endl;

		cout << "You explain your reason for confronting him, what the townsfolk want you to do." << endl << endl;

		cout << dragonLord.GetName() << ": ";
		cout << "Destroy their town? I desire no such thing! This is my ancestral home and I am here to raise my son. The damage done to the farm was an unfortunate incident caused by my son, who just develped his fire." << endl << endl;

		cout << "Well, that\'s nice to know, but the townsfolk don\'t know about any of that." << endl << endl;

		cout << dragonLord.GetName() << ": ";
		cout << "Hm, I suppose you\'re right. My family has never attempted to communicate with the humans living below us before, but maybe it\'s time we start. Since you took the initiative to speak with me, ";
		cout << "would you assist me in this task? Once everything is settled, I will make sure you are well-payed." << endl << endl;

		cout << "You agree to his terms. The meeting between the mayor and the dragon lord is awkward at first, but with your help, the manage to come to an understanding. Now the town has an extra guardian ";
		cout << "to protect them. Your pockets and wallet full with more money than you ever expected, you wave your goodbyes to the town, ready for your next adventure." << endl << endl;
		endResult = "peace end";
	}

	return endResult;
}

string NoPrepEnd()
{
	string endResult;

	if (weapon.inInventory == true)
	{
		cout << "You make a mad dash at the dragon, weapon drawn. The dragon slaps you away like an insect, snapping your weapon in two. ";
	}
	else
	{
		cout << "You make a mad dash at the dragon. The dragon slaps you away like an insect. ";
	}

	cout << "You have no options now. As the dragon looms over you, deciding your fate, all you can think about is how you should have prepared for this fight better." << endl << endl;

	endResult = "game over";

	return endResult;
}

string FightDragon()
{
	string endResult;

	if (weapon.inInventory == true && weapon.name == "Dragonslayer")
	{
		cout << "You rush towards the dragon, silver weapon in hand. The dragon looks startled at the sight of the weapon. Scared, even. The fight feels long and brutal, ";
		cout << "but in the end, you are victorious. You feel a sense of accomplishment, standing over the body of the dragon that terrorized a town for too long. ";
		cout << "However, in the back of your mind, you start to wonder if perhaps there was another way." << endl << endl;

		endResult = "violent end";
	}
	else if (weapon.inInventory == true && weapon.name != "Dragonslayer")
	{
		endResult = NoPrepEnd();
	}
	else
	{
		endResult = NoPrepEnd();
	}

	return endResult;
}

string ConfrontDragon(int peaceEnd, int violentEnd)
{
	int minPeace = 3;
	int minViolent = 1;
	string endResult;
	cout << endl;
	if (peaceEnd >= minPeace)
	{
		endResult = NegotiateDragon();
	}
	else if (violentEnd >= minViolent)
	{
		endResult = FightDragon();
	}
	else
	{
		endResult = NoPrepEnd();
	}
	return endResult;
}

void AttemptToLeave()
{
	cout << endl;
	cout << "Seeing the large dragon in front of you, you start second guessing you decisions. You begin to back up and turn around, racing toward the door. ";
	cout << "You hear a loud thump of the dragon\'s tail and suddenly the door to the throne room is blocked off by bars. Why would those even be installed? ";
	cout << "But pondering that is pointless; they\'re there and they\'re blocking your exit. You have no choice: you must face the dragon." << endl << endl;
}