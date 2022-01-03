#include <iostream>
#include <string>
#include "Character.h"

using namespace std;


Character::Character()
{
	name = "no name";
	patience = 0;
	violentEnd = 0;
	peaceEnd = 0;
}
void Character::SetName(string charName)
{
	name = charName;
}
void Character::SetPatience(int charPatience)
{
	patience = charPatience;
}
void Character::SetViolentEnd(int supportViolentEnd)
{
	violentEnd = supportViolentEnd;
}
void Character::SetPeaceEnd(int supportPeaceEnd)
{
	peaceEnd = supportPeaceEnd;
}
string Character::GetName()
{
	return name;
}
int Character::GetPatience()
{
	return patience;
}
int Character::GetViolentEnd()
{
	return violentEnd;
}
int Character::GetPeaceEnd()
{
	return peaceEnd;
}

TownGuard::TownGuard()
{
	location = "no location";
}
void TownGuard::SetLocation(string guardLoc)
{
	location = guardLoc;
}
string TownGuard::GetLocation()
{
	return location;
}

Citizen::Citizen()
{
	citizenType = "no role";
	money = 0;
}
void Citizen::SetCitizenType(string citizenRole)
{
	citizenType = citizenRole;
}
void Citizen::SetMoney(int gold)
{
	money = gold;
}
string Citizen::GetCitizenType()
{
	return citizenType;
}
int Citizen::GetMoney()
{
	return money;
}

Vendor::Vendor()
{
	shopType = "no shop";
	item = "no item";
}
void Vendor::SetShopType(string store)
{
	shopType = store;
}
void Vendor::SetItem(string helpfulItem)
{
	item = helpfulItem;
}
string Vendor::GetShopType()
{
	return shopType;
}
string Vendor::GetItem()
{
	return item;
}

Minion::Minion()
{
	minionType = "no role";
	onDuty = "duty not set";
}
void Minion::SetMinionType(string minionRole)
{
	minionType = minionRole;
}
void Minion::SetOnDuty(string isOnDuty)
{
	onDuty = isOnDuty;
}
string Minion::GetMinionType()
{
	return minionType;
}
string Minion::GetOnDuty()
{
	return onDuty;
}

Dragon::Dragon()
{
	dragonType = "no role";
	spokeWith = false;
}
void Dragon::SetDragonType(string dragonRole)
{
	dragonType = dragonRole;
}
void Dragon::SetSpokeWith(bool spokeDragon)
{
	spokeWith = spokeDragon;
}
string Dragon::GetDragonType()
{
	return dragonType;
}
bool Dragon::GetSpokeWith()
{
	return spokeWith;
}

