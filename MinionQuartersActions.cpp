#include <iostream>
#include <string>
#include <vector>
#include "MinionQuartersActions.h"

using namespace std;

void ApproachOffDutyMinion()
{
	cout << endl;
	cout << "You walk around casually, trying to act like you belong here. It seems to be working because no one has bothered to stop you. As you walk around, you over hear one of the servants." << endl << endl;

	cout << minionServant.GetName() << ": ";
	cout << "I can\'t believe I got assigned the Hoard again. I\'m tired of being a glorified babysitter. I love the little munchkin as much as the next gal, but I can\'t take the tantrums anymore!" << endl << endl;

	cout << "Little munchkin? What in the world is in the hoard room? Maybe something to check out, if you can get in there." << endl << endl;
}

void StealSleepingMinion(Inventory &throneKey)
{
	cout << endl;
	cout << "No one is watching you as you approach a sleeping guard. He still has his uniform on, which means he probably has something good in his pockets. ";
	cout << "You dig around, eventually finding an ornate key. Aha! This must be for the throne room. Slipping the key into your own pocket, you quickly move away from the slumbering minion." << endl << endl;
	cout << "Added Throne Room Key to your inventory" << endl << endl;
	throneKey.inInventory = true;
	throneKey.name = "Throne Room Key";
}
