#include <iostream>
#include <string>
#include <vector>
#include "HoardLibraryKitchenActions.h"

using namespace std;

void ExamineTreasure()
{
	cout << endl;
	cout << "Gold and jewels beyond anything you could ever imagine! That\'s what you think looking at this hoard. You want to take some, but even you know ";
	cout << "taking from a dragon can only end badly. Best to wait until after the dragon is taken care of. You\'ll remember this room for later." << endl << endl;
}

void TalkToLibraryServant()
{
	cout << "1. Ask about lair history" << endl;
	cout << "2. Insult" << endl;
	cout << "3. Leave conversation" << endl << endl;
}

void AskLairHistory()
{
	cout << minionServant.GetName() << ": ";
	cout << "Of course I can tell you about the castle! It has a long, storied history. It was built 3000 years ago, carved right into the mountain side by the Dragon lord\'s ancestor. ";
	cout << "It\'s been their family\'s home every since. Dragons take about 300 years to reach maturity, so once they find a mate and are ready to have children, they return to the family home. ";
	cout << "The lord returned six months ago with his mate to raise their son. Of course, the town at the base of the mountain was founded about 800 years ago while the family was gone. ";
	cout << "Things have been tense since the dragons first returned after the settlers arrived." << endl << endl;

	cout << "Well, that certainly explained a few things. Doesn\'t explain the destruction the town apparently suffers whenever a dragon is around, but it\'s a start." << endl << endl;
}

void LibraryInsult(int &totalInfamy)
{
	if (totalInfamy == 0)
	{
		cout << "The librarian stares at you, hands on hips." << endl << endl;

		cout << minionServant.GetName() << ": ";
		cout << "Now listen here, child, I will not tolerate such behavior in my library. Is that clear?" << endl << endl;

		cout << "Something about her compels you to listen. Maybe it\'s because she looks like your grandmother, and why would you not listen to your grandmother? ";
		cout << "You quickly nod your head to let her know you understand. No way are you angering the library grandma." << endl << endl;
		totalInfamy = AddInfamy(totalInfamy);
	}
	else
	{
		cout << "You\'re tempted and open your mouth to say something, but as if she senses your intention, the librarian gives you a look of promised death - or promise to be kicked out. You snap your mouth shut." << endl << endl;
	}
}

void LeaveLibraryConversation()
{
	cout << minionServant.GetName() << ": ";
	cout << "Feel free to stop by anytime!" << endl << endl;
}

void ApproachLibraryServant()
{
	int totalInfamy = 0;
	int playerChoice;
	cout << "You walk up to the servant. The librarian, probably." << endl << endl;

	do
	{
		TalkToLibraryServant();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				AskLairHistory();
				break;
			case 2:
				LibraryInsult(totalInfamy);
				break;
			case 3:
				LeaveLibraryConversation();
				break;
			default:
				break;
		} 
	} while (playerChoice != 3);
}

void ExamineBooks()
{
	cout << endl;
	cout << "Most of the books seem ancient. You\'re too scared they might fall apart if you touch them." << endl << endl;
}

void AskMeal()
{
	cout << minionServant.GetName() << ": ";
	cout << "Curious about the meal? Well, this meal is for our lord\'s darling little boy. He\'s a growing dragon, so he needs all the nutrients and meat he can get." << endl << endl;

	cout << "She seems proud of what she\'s preparing, but you haven\'t seen anyone make beef and chicken look any less appetizing in your life. Best not question what else is in the meal." << endl << endl;
}

void KitchenInsult(int &kitchenPatience)
{
	int playerChoice;
	kitchenPatience = 0;
	cout << "The cook snaps her head to look you straight in the eyes. She looks slightly confused, as if she\'s not sure she heard you correctly." << endl << endl;
	kitchenPatience = AddInfamy(kitchenPatience);

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		kitchenPatience = AddInfamy(kitchenPatience);
		cout << "She crosses her arms, eyes narrowed." << endl << endl;
		cout << minionServant.GetName() << ": ";
		cout << "You want to run that by me again?" << endl << endl;

		ContInsult(playerChoice);

		if (playerChoice == 1)
		{
			kitchenPatience = AddInfamy(kitchenPatience);
			cout << "One hand on hip, the other wielding a wooden spoon, she pushes you out of the room." << endl << endl;
			cout << minionServant.GetName() << ": ";
			cout << "Out of my kitchen! Are you a child? You must be, behaving like that! Think hard about that attitude before you set foot in here again!" << endl << endl;
		}
	}
}

void LeaveKitchenConversation()
{
	cout << minionServant.GetName() << ": ";
	cout << "Leaving already? Well, alright then. Thanks for taking the time to talk with me!" << endl << endl;
}

void TalkToKitchenServant()
{
	cout << "1. Ask about meal" << endl;
	cout << "2. Insult" << endl;
	cout << "3. Leave conversation" << endl << endl;
}

void ApproachKitchenServant(int &totalInfamy)
{
	int playerChoice;
	cout << "You walk up to the cook." << endl << endl;

	do
	{
		TalkToKitchenServant();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
			case 1:
				AskMeal();
				break;
			case 2:
				KitchenInsult(totalInfamy);
				break;
			case 3:
				LeaveKitchenConversation();
				break;
			default:
				break;
		}
	} while (playerChoice != 3);
}

void ExamineIngredients()
{
	cout << endl;
	cout << "The ingredients look rather...normal, considering they\'re for dragons. Huh, you weren\'t expecting that." << endl << endl;
}