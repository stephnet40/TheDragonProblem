#include <iostream>
#include <string>
#include <vector>
#include "ShopsActions.h"

using namespace std;

void TalkToBarkeep()
{
	cout << "1. Ask about town" << endl;
	cout << "2. Ask about work" << endl;
	cout << "3. Buy food" << endl;
	cout << "4. Insult" << endl;
	cout << "5. Leave conversation" << endl << endl;
}

void BarAskTown()
{
	cout << barkeep.GetName() << ": ";
	cout << "If you\'re here, you already know the most important things for a traveler to know. We got a smithy for weapons, a general store for all your other goods, and here to satisfy your appetite." << endl << endl;

	cout << "You always thought barkeepers were supposed to be the go-to people for town gossip. Was that wrong? ";
	cout << "Something on your face must have shown your disappointment because the man rolls his eyes and sighs." << endl << endl;

	cout << barkeep.GetName() << ": ";
	cout << "Look, if you\'re sniffing out work, just say it and I\'ll tell you anything you want to know. Otherwise, I ain\'t about to start gossiping about my neighbors with some random traveler." << endl << endl;
}

void BarAskWork(Inventory &map)
{
	cout << barkeep.GetName() << ": ";
	cout << "Right now, the only job worth doing around here is dealing with the dragon hanging out on our mountain. That\'s all anyone\'s been talking about, anyway. ";
	cout << "Not something many people are willing to take on anymore, especially after the first month. We lost at least ten travelers to that creature during that month alone." << endl << endl;

	cout << "You squash any panic before it shows. Instead, you set a determined expression on your face. You can do this! Just because those adventurers couldn\'t do it doesn\'t mean you can\'t." << endl << endl;

	cout << "Right?" << endl << endl;

	cout << "The barkeepers seems to buy your determination." << endl << endl;

	cout << barkeep.GetName() << ": ";
	cout << "If you want to take that dragon on, be my guest. Just don\'t go unprepared. Visit the smithy, at least. Get yourself a good weapon. Oh, and take this. ";
	cout << "I managed to get my hands on this map a couple weeks ago. Don\'t ask how. It\'s a map of the dragon\'s lair. It should help you at least get in." << endl << endl;

	cout << "Added Map of Lair to your inventory." << endl << endl;

	map.inInventory = true;
	map.name = "Map of Lair";
}

void BuyFood(int &totalGold, Inventory &food)
{
	int jerkyPrice = 5;
	if (totalGold >= jerkyPrice)
	{
		cout << "You buy some jerky for the road. After you deal with the dragon, you\'ll make sure to come back for a full celebration feast." << endl;
		cout << "-" << jerkyPrice << "Gold" << endl;
		totalGold -= jerkyPrice;
		DisplayTotalGold(totalGold);
		food.inInventory = true;
		food.name = "Jerky";
	}
	else
	{
		cout << "You don\'t have enough money to buy anything, leaving you stomach to growl in protest." << endl << endl;
	}
}

void BarInsult(int &barkeepPatience)
{
	barkeepPatience = 0;
	barkeepPatience = AddInfamy(barkeepPatience);
	cout << "The man stops what he\'s doing, placing the half-clean mug on the counter. He leans over the bar, stopping mere inches from you face." << endl << endl;

	cout << barkeep.GetName() << ": ";
	cout << "Now you listen here: I don\'t have patience for mouthy travelers. See all these dangerous looking patrons of mine? All learned to keep their mouths shut. ";
	cout << "You want a fight? Go fight the dragon. Now get out of my tavern." << endl << endl;

	cout << "There\'s a rather dangerous implicit threat lingering in his eyes. You decide to listen and leave." << endl << endl;
}

void LeaveBarConversation()
{
	cout << "As you turn to leave the bar, the barkeeper nods to you." << endl << endl;

	cout << barkeep.GetName() << ": ";
	cout << "Thank you for your patronage." << endl << endl;
}

void ApproachBarkeep(int &totalGold, int &totalInfamy, Inventory &map, Inventory &food)
{
	int playerChoice;

	cout << endl;
	cout << "You walk up to the barkeeper, who\'s busy cleaning and organized various mugs and dishes. The man glances up from his task. He walks over to you, but doesn\'t stop his cleaning." << endl << endl;
	do
	{
		TalkToBarkeep();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
			case 1:
				BarAskTown();
				break;
			case 2:
				BarAskWork(map);
				break;
			case 3:
				BuyFood(totalGold, food);
				break;
			case 4:
				BarInsult(totalInfamy);
				playerChoice = 5;
				break;
			case 5:
				LeaveBarConversation();
				break;
			default:
				ClearInput();
				break;
		}

	} while (playerChoice != 5);
}

void TalkToShopkeep()
{
	cout << "1. Ask about dragon" << endl;
	cout << "2. Ask about lair" << endl;
	cout << "3. Buy item" << endl;
	cout << "4. Insult" << endl;
	cout << "5. Leave conversation" << endl << endl;
}

void ShopAskDragon()
{
	cout << shopkeep.GetName() << ": ";
	cout << "Oh, you\'ve heard of our dragon problem? Of course you have, you\'re a wandering adventurer. Why else would you be in our humble town? ";
	cout << "Well, the dragon showed up six months ago. Everyone\'s worried about the damage it\'ll cause, though the only thing destroyed has been a farm. ";
	cout << "Not much else to tell. Nothing else has happened yet, but everyone in town wants someone to deal with it. I hope you\'ll help." << endl << endl;
}

void ShopAskLair(Inventory &hoardKey, int &peaceEnd)
{
	cout << "She blinks at you, slightly confused." << endl << endl;

	cout << shopkeep.GetName() << ": ";
	cout << "The lair? I\'ve never been there. Although...I have heard that dragons like to hoard valuables. I have this key that my grandmother found when she was young. ";
	cout << "Back then, the lair was abandoned. Take it, you might find something. Let me know if you do." << endl << endl;

	cout << "She pauses, then sighs." << endl << endl;

	cout << shopkeep.GetName() << ": ";
	cout << "Besides, if you look around, you might find out what\'s really going on. My friend Elena is insistant that the dragon can be reasoned with. ";
	cout << "I don\'t know if that\'s true, but if you figure out something, Elena would appreciate it." << endl << endl;

	cout << "Added Hoard Key to your inventory" << endl << endl;
	hoardKey.inInventory = true;
	hoardKey.name = "Hoard Key";
	peaceEnd += shopkeep.GetPeaceEnd();
}

void BuyItem(int &totalGold, Inventory &toy)
{
	int toyPrice = 10;
	cout << "You peruse the items on display. You aren\'t sure if there\'s anything you want until something catches your eye: a stuffed, toy dragon." << endl << endl;

	cout << shopkeep.GetName() << ": ";
	cout << "Ah, I see our new souvenir has caught your eye. We thought it would be fun to capitalize on the whole dragon thing. Find the silver lining, you know. It\'s ten gold, if you want it." << endl << endl;

	if (totalGold >= toyPrice)
	{
		cout << "You quickly nod. The plush is adorable! Why wouldn\'t you want it...as a gift, of course. For your young neighbor back home. Because tough adventurers don\'t need stuffed dragons. Right." << endl;
		cout << "-" << toyPrice << " Gold" << endl;
		totalGold -= toyPrice;
		DisplayTotalGold(totalGold);
		toy.inInventory = true;
		toy.name = "Dragon Plush";
	}
	else
	{
		cout << "You slowly shake your head. You don\'t have enough money for it, so you sadly turn away from the adorable toy." << endl << endl;
	}
}

void ShopInsult(int &shopkeepPatience)
{
	int playerChoice;
	shopkeepPatience = 0;
	shopkeepPatience = AddInfamy(shopkeepPatience);
	cout << "The woman shifts her weight to the heel of her right foot and crosses her arms, an eyebrow raised." << endl << endl;

	cout << shopkeep.GetName() << ": ";
	cout << "Excuse me? I\'m going to give you one chance to fix your attitude. Otherwise, you can get out of my store." << endl << endl;

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		shopkeepPatience = AddInfamy(shopkeepPatience);
		cout << shopkeep.GetName() << ": ";
		cout << "That\'s it. Out! Out of my store before I call the guards! You can come back when you learn some manners." << endl << endl;

		cout << "What\'s her problem, you wonder as you leave." << endl << endl;
	}
}

void LeaveShopConversation()
{
	cout << "You turn around to leave. The shopkeeper waves at you, a smile on her face." << endl << endl;
	cout << shopkeep.GetName() << ": ";
	cout << "Thanks for stopping by!" << endl << endl;
}

void ApproachShopkeep(int &totalGold, int &totalInfamy, Inventory &hoardKey, Inventory &toy, int &peaceEnd)
{
	int playerChoice;
	cout << endl;
	cout << "You approach the shop counter, where the shopkeeper welcomes you." << endl << endl;

	do
	{
		TalkToShopkeep();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
		case 1:
			ShopAskDragon();
			break;
		case 2:
			ShopAskLair(hoardKey, peaceEnd);
			break;
		case 3:
			BuyItem(totalGold, toy);
			break;
		case 4:
			ShopInsult(totalInfamy);
			if (totalInfamy > shopkeep.GetPatience())
			{
				playerChoice = 5;
			}
			break;
		case 5:
			LeaveShopConversation();
			break;
		default:
			ClearInput();
			break;
		}

	} while (playerChoice != 5);
}

void TalkToBlacksmith()
{
	cout << "1. Ask about dragon" << endl;
	cout << "2. Ask about lair" << endl;
	cout << "3. Buy weapon" << endl;
	cout << "4. Insult" << endl;
	cout << "5. Leave conversation" << endl << endl;
}

void SmithAskDragon()
{
	cout << blacksmith.GetName() << ": ";
	cout << "It\'s big, it\'s nasty, and it breathes fire. Not much else to say." << endl << endl;

	cout << "You wait for him to continue, but he doesn\'t. Not much of a talker, then." << endl << endl;
}

void SmithAskLair(Inventory &armoryKey, int &violentEnd)
{
	cout << blacksmith.GetName() << ": ";
	cout << "You planning to fight it? Well, I ain\'t stopping ya, but you might want to arm yourself. Take a look \'round here before you go." << endl << endl;

	cout << "He grabs something from under the counter and hands it to you." << endl << endl;

	cout << blacksmith.GetName() << ": ";
	cout << "Take this key. It came into my possession not too long ago. Heard it unlocks an armory full of weapons from fallen warriors. There might be some ultimate dragon-slaying weapon in there. Who knows." << endl << endl;

	cout << "Added Armory Key to your inventory." << endl << endl;
	violentEnd += blacksmith.GetViolentEnd();
	armoryKey.inInventory = true;
	armoryKey.name = "Armory Key";
}

void BuyWeapon(int &totalGold, Inventory &weapon)
{
	int playerChoice;
	cout << "You see two potential weapons - a steel sword and a wooden one." << endl << endl;

	cout << blacksmith.GetName() << ": ";
	cout << "I\'d recommend that steel sword to really protect you, but the wooden sword would work in a pinch. Just avoid combat if you can." << endl << endl;

	cout << "1. Buy Steel Sword (15 Gold)" << endl;
	cout << "2. Buy Wooden Sword (5 Gold)" << endl;
	cout << "3. Don\'t buy anything" << endl << endl;
	cin >> playerChoice;
	cout << endl;

	int steelPrice = 15;
	int woodPrice = 5;
	int priceDiff = steelPrice - woodPrice;

	switch (playerChoice)
	{
		case 1:
			if (weapon.inInventory == false)
			{
				if (totalGold >= steelPrice)
				{
					cout << "Added Steel Sword to your inventory." << endl;
					totalGold -= steelPrice;
					DisplayTotalGold(totalGold);
					weapon.inInventory = true;
					weapon.name = "Steel Sword";
				}
				else
				{
					cout << "You can\'t afford this weapon." << endl << endl;
				}
			}
			else if (weapon.inInventory == true && weapon.name == "Wooden Sword")
			{
				if (totalGold >= priceDiff)
				{
					cout << "You decide to trade your wooden sword for a steel sword." << endl;
					cout << "Removed Wooden Sword from your inventory." << endl;
					cout << "Added Steel Sword to your inventory." << endl;
					totalGold -= priceDiff;
					DisplayTotalGold(totalGold);
					weapon.name = "Steel Sword";
				}
				else
				{
					cout << "You would like to trade swords, but you don\'t have the money to do so." << endl << endl;
				}
			}
			else
			{
				cout << "You already have this weapon." << endl;
			}
			break;
		case 2:
			if (weapon.inInventory == false)
			{
				if (totalGold >= woodPrice)
				{
					cout << "Added Wooden Sword to your inventory." << endl;
					totalGold -= woodPrice;
					DisplayTotalGold(totalGold);
					weapon.inInventory = true;
					weapon.name = "Wooden Sword";
				}
				else
				{
					cout << "You can\'t afford this weapon." << endl << endl;
				}
			}
			else if (weapon.inInventory == true && weapon.name == "Steel Sword")
			{
				cout << "You decide to trade your steel sword for a wooden sword." << endl;
				cout << "Removed Steel Sword from your inventory." << endl;
				cout << "Added Wooden Sword to your inventory." << endl;
				totalGold += priceDiff;
				DisplayTotalGold(totalGold);
				weapon.name = "Wooden Sword";
			}
			else
			{
				cout << "You already have this weapon." << endl << endl;
			}
			break;
		case 3:
			cout << "You decide not to buy anything." << endl << endl;
			break;
		default:
			ClearInput();
			break;
	}
}

void SmithInsult(int &blacksmithPatience)
{
	int playerChoice;
	blacksmithPatience = 0;
	blacksmithPatience = AddInfamy(blacksmithPatience);

	cout << "The man\'s eyes narrow. He slowly moves from his position and starts moving to a display rack, eyes never leaving you." << endl << endl;

	ContInsult(playerChoice);

	if (playerChoice == 1)
	{
		blacksmithPatience = AddInfamy(blacksmithPatience);
		cout << "The blacksmith picks up a very sharp, very large battleaxe. He stalks towards you. You don\'t wait for him to reach you - you bolt out of the building. ";
		cout << "In fact, you don\'t stop outside the building. You keep running until you are long out of town, away from the crazy blacksmith. Time to find another town, ";
		cout << "one without a blacksmith ready to severe your head from your body." << endl << endl;
	}
}

void LeaveSmithConversation()
{
	cout << "The blacksmith just grunts as you leave." << endl << endl;
}

void ApproachBlacksmith(int &totalGold, int &totalInfamy, Inventory &armoryKey, Inventory &weapon, int &violentEnd)
{
	int playerChoice;
	cout << endl;
	cout << "Refusing to be intimidated, you approach the blacksmith." << endl;
	cout << endl;
	do
	{
		TalkToBlacksmith();
		cin >> playerChoice;
		cout << endl;

		switch (playerChoice)
		{
		case 1:
			SmithAskDragon();
			break;
		case 2:
			SmithAskLair(armoryKey, violentEnd);
			break;
		case 3:
			BuyWeapon(totalGold, weapon);
			break;
		case 4:
			SmithInsult(totalInfamy);
			if (totalInfamy > blacksmith.GetPatience())
			{
				playerChoice = 5;
			}
			break;
		case 5:
			LeaveSmithConversation();
			break;
		default:
			ClearInput();
			break;
		}

	} while (playerChoice != 5);
}

void ExitBuilding()
{
	cout << endl;
	cout << "You leave the building, returning to the market." << endl << endl;
}