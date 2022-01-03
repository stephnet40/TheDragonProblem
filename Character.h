#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

class Character
{
	private:
		string name;
		int patience;
		int violentEnd;
		int peaceEnd;
	public:
		Character();
		void SetName(string charName);
		void SetPatience(int charPatience);
		void SetViolentEnd(int supportViolentEnd);
		void SetPeaceEnd(int supportPeaceEnd);
		string GetName();
		int GetPatience();
		int GetViolentEnd();
		int GetPeaceEnd();
};

class TownGuard : public Character
{
	private:
		string location;
	public:
		TownGuard();
		void SetLocation(string guardLoc);
		string GetLocation();
};

class Citizen : public Character
{
	private:
		string citizenType;
		int money;
	public:
		Citizen();
		void SetCitizenType(string citizenRole);
		void SetMoney(int gold);
		string GetCitizenType();
		int GetMoney();		
};

class Vendor : public Character
{
	private:
		string shopType;
		string item;
	public:
		Vendor();
		void SetShopType(string store);
		void SetItem(string helpfulItem);
		string GetShopType();
		string GetItem();
};

class Minion : public Character
{
	private:
		string minionType;
		string onDuty;
	public:
		Minion();
		void SetMinionType(string minionRole);
		void SetOnDuty(string isOnDuty);
		string GetMinionType();
		string GetOnDuty();
};

class Dragon : public Character
{
	private:
		string dragonType;
		bool spokeWith;
	public:
		Dragon();
		void SetDragonType(string dragonRole);
		void SetSpokeWith(bool spokeDragon);
		string GetDragonType();
		bool GetSpokeWith();
};

#endif

