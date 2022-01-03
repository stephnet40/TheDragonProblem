#include <iostream>
#include <string>
#include <vector>
#include "ArmoryActions.h"

using namespace std;

void ChooseWeapon()
{
	cout << "1. Take bejewled sword" << endl;
	cout << "2. Take silver sword" << endl;
	cout << "3. Take nothing" << endl;
}

void LeaveBehindWeapon()
{
	cout << "You don\'t want to carry two swords, so you leave the " << weapon.name << " behind." << endl << endl;
}

void TakeBejewled(Inventory &weapon)
{
	cout << "You take the bejeweled sword. Something this fancy has to be useful, right?" << endl << endl;

	if (weapon.inInventory == true)
	{
		LeaveBehindWeapon();
	}

	weapon.inInventory = true;
	weapon.name = "Bejewled Sword";
}

void TakeSilver(Inventory &weapon)
{
	cout << "You take the silver sword. It looks like the lease impressive sword of the lot, but also the most effective. It just seems important." << endl << endl;

	if (weapon.inInventory == true)
	{
		LeaveBehindWeapon();
	}

	weapon.inInventory = true;
	weapon.name = "Dragonslayer";
}

void TakeNothing()
{
	if (weapon.inInventory == true)
	{
		cout << "You already have a great weapon. You don\'t need anything else." << endl << endl;
	}
	else
	{
		cout << "You managed to get this far without a weapon, why do you need one now?" << endl << endl;
	}
}

void ExamineWeapons(Inventory &weapon)
{
	int playerChoice;
	cout << endl;
	cout << "You take a look at the various weapons. Most of them put what you saw at the smithy to shame. Two swords catch your eye: ";
	cout << "A jewel-encrusted sword that looks more decorative than functional and a large, well crafted silver sword that seems deceptively simple." << endl << endl;

	do
	{
		ChooseWeapon();
		cin >> playerChoice;
		cout << endl;
		switch (playerChoice)
		{
		case 1:
			TakeBejewled(weapon);
			break;
		case 2:
			TakeSilver(weapon);
			break;
		case 3:
			TakeNothing();
			break;
		default:
			ClearInput();
			break;
		}
	} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
	
}