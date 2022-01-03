#include <iostream>
#include <string>
#include <vector>
#include "PrivateChambersActions.h"

using namespace std;

void TalkToFemaleDragon()
{
	cout << "1. Ask about Dragon lord" << endl;
	cout << "2. Ask about conflict with town" << endl;
	cout << "3. Insult" << endl;
	cout << "4. Leave conversation" << endl;
}

void AskAboutLord()
{
	cout << "She tilts her head and her mouth twitches. You hope that means she\'s happy and not getting ready to eat you." << endl << endl;

	cout << dragonWife.GetName() << ": ";
	cout << "My mate? Why, he\'s a wonderful husband, as your humans would call him, and a doting father. A real softie, too!" << endl << endl;

	cout << "Softie? A dragon? You find it hard to believe that a flying, fire-breathing lizard that\'s bigger than house could be described with such a word. You feel a rumble - a dragon chuckle." << endl << endl;

	cout << dragonWife.GetName() << ": ";
	cout << "I see you\'re skeptical. Most humans are. But it\'s the truth. He likes to act tough - needs to uphold his dragon dignity - but he doesn\'t mean any harm, ";
	cout << "especially towards the town we overlook. He actually has a soft-spot for those humans; reminds him of his childhood." << endl << endl;

	cout << "This wasn\'t a twist you were expecting. Who knew dragons were just like people?" << endl << endl;
}

void AskConflict(Inventory &throneKey, Dragon &dragonWife, int &peaceEnd)
{
	cout << dragonWife.GetName() << ": ";
	cout << "Hm? Conflict? Oh, you mean that farm my son got into? My apologies. He was in a mischieveous mood and managed to get out of the castle. He found the farm and wanted to play. ";
	cout << "His fire is just developing, so he lost some control. Managed to take a cow, too. We would have returned it, but it wasn\'t exactly in living condition anymore. We scolded the guards about the incident. ";
	cout << "They know better than to let a baby dragon go off alone." << endl << endl;

	cout << "That certainly explained the destroyed farm you heard about while in town. But you also heard about a legend about dragons destroying the town every few hundred years. What\'s up with that?" << endl << endl;

	cout << dragonWife.GetName() << ": ";
	cout << "The townsfolk have a legend about us? Oh, of course they do. You humans live such short lives, after all. My mate\'s family uses this castle as a nest. We raise our children, we all leave, ";
	cout << "and when the children are old enough, they return to raise their own. Baby dragons can be destructive, though, so the surrounding area often gets damaged as a result." << endl << endl;

	cout << "That...makes a lot of sense, actually. But the townsfolk want the dragon dealt with, and now you aren\'t sure if you can bring yourself to kill him, and you definitely can\'t kill his family." << endl << endl;

	cout << dragonWife.GetName() << ": ";
	cout << "There\'s clearly been a misunderstanding. Here, take this key to my mate\'s throne room. Talk with him. I\'m sure you two can come up with something that pleases everyone." << endl << endl;

	if (throneKey.inInventory == false)
	{
		cout << "Added Throne Room Key to your inventory" << endl << endl;
		throneKey.inInventory = true;
		throneKey.name = "Throne Room Key";
	}

	peaceEnd += dragonWife.GetPeaceEnd();
	dragonWife.SetSpokeWith(true);
}

void InsultDragon()
{
	cout << "You\'re about to say something your mother would call rude, but seeing the size of the dragon in front of you, you think better of it. ";
	cout << "You\'d rather not be eaten, thank you very much." << endl << endl;
}

void LeaveFemaleConversation()
{
	cout << "You say goodbye to the female dragon." << endl << endl;
	cout << dragonWife.GetName() << ": ";
	cout << "Thank you so much for the conversation. I rarely get to speak with humans from outside the mountain. Please, visit again." << endl << endl;
}

void ApproachFemaleDragon(Inventory &throneKey, Dragon &dragonWife, int &peaceEnd)
{
	int playerChoice;
	cout << "You approach the large dragon, the mother of the baby dragon in the room. This is a bit intimidating, but you are a brave adventurer! You can do it!" << endl << endl;
	do
	{
		TalkToFemaleDragon();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				AskAboutLord();
				break;
			case 2:
				AskConflict(throneKey, dragonWife, peaceEnd);
				break;
			case 3: 
				InsultDragon();
				break;
			case 4:
				LeaveFemaleConversation();
				break;
			default:
				break;
		}
	} while (playerChoice != 4);

}

void TalkToYoungDragon()
{
	cout << "1. Ask about life" << endl;
	cout << "2. Play with dragon" << endl;
	cout << "3. Leave conversation" << endl << endl;
}

void AskLife()
{
	cout << "You ask the young dragon about his life, but he doesn\'t seem to quite understand." << endl << endl;

	cout << dragonChild.GetName() << ": ";
	cout << "Play? Play! Play!" << endl << endl;

	cout << "The mother rumbles, startling you. Then you realize she\'s chuckling." << endl << endl;

	cout << dragonWife.GetName() << ": ";
	cout << "I\'m afraid he\'s too young to communicate, especially with humans. Right now, he just wants to play. He\'s a happy, healthy boy, if that\'s what you\'re concerned about." << endl << endl;

	cout << "It\'s disappointing you can\'t talk with the baby dragon, but looking at those big, adorable eyes, you can\'t bring yourself to be all that upset." << endl << endl;
}

void PlayDragon(Inventory &toy)
{
	cout << "You decide to play with dragon, enjoying yourself though also hoping you don\'t get hurt from his claws or sharp teeth." << endl << endl;

	if (toy.inInventory == true)
	{
		cout << "As you play, the dragon starts to get distracted by your bag. He noses it open and pulls out your dragon plush, holding it happily in his jaws. ";
		cout << "You\'re about to tell him to put it back, but seeing his gleeful expression stops you. Well, you can always get a new one." << endl << endl;
		toy.inInventory = false;
	}
}

void LeaveYoungConversation()
{
	cout << "You turn to leave the young dragon, but he starts to whine. You reassure him you\'ll be back to play later, calming him down and allowing you to leave." << endl << endl;
}

void ApproachYoungDragon(Inventory &toy)
{
	int playerChoice;
	cout << "You\'ve never seen a baby dragon before, or even really though about them even existing, so you let your curiosity bring you to the young dragon." << endl << endl;

	do
	{
		TalkToYoungDragon();
		cin >> playerChoice;
		switch (playerChoice)
		{
			case 1:
				AskLife();
				break;
			case 2:
				PlayDragon(toy);
				break;
			case 3:
				LeaveYoungConversation();
				break;
			default:
				break;
		}
	} while (playerChoice != 3);
}