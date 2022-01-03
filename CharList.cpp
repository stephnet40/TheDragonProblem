#include <iostream>
#include <string>
#include "CharList.h"

using namespace std;

TownGuard CreateEntryGuard(TownGuard entryGuard)
{
	entryGuard.SetName("Entry Guard");
	entryGuard.SetPatience(2);
	entryGuard.SetViolentEnd(0);
	entryGuard.SetPeaceEnd(0);
	entryGuard.SetLocation("town entrance");

	return entryGuard;
}

TownGuard CreateExitGuard(TownGuard exitGuard)
{
	exitGuard.SetName("Exit Guard");
	exitGuard.SetPatience(5);
	exitGuard.SetViolentEnd(0);
	exitGuard.SetPeaceEnd(0);
	exitGuard.SetLocation("town exit");

	return exitGuard;
}

TownGuard CreateMarketGuard(TownGuard marketGuard)
{
	marketGuard.SetName("Market Guard");
	marketGuard.SetPatience(5);
	marketGuard.SetViolentEnd(0);
	marketGuard.SetPeaceEnd(0);
	marketGuard.SetLocation("market");

	return marketGuard;
}

Citizen CreateBeggar(Citizen beggar)
{
	beggar.SetName("Town Beggar");
	beggar.SetPatience(3);
	beggar.SetViolentEnd(0);
	beggar.SetPeaceEnd(0);
	beggar.SetCitizenType("rumors");
	beggar.SetMoney(0);

	return beggar;
}

Citizen CreateAngryCitizen(Citizen angryCitizen)
{
	angryCitizen.SetName("Angry Citizen");
	angryCitizen.SetPatience(1);
	angryCitizen.SetViolentEnd(2);
	angryCitizen.SetPeaceEnd(0);
	angryCitizen.SetCitizenType("decide ending");
	angryCitizen.SetMoney(10);

	return angryCitizen;
}

Citizen CreateConcernedCitizen(Citizen concernedCitizen)
{
	concernedCitizen.SetName("Concerned Citizen");
	concernedCitizen.SetPatience(2);
	concernedCitizen.SetViolentEnd(0);
	concernedCitizen.SetPeaceEnd(2);
	concernedCitizen.SetCitizenType("decide ending");
	concernedCitizen.SetMoney(10);

	return concernedCitizen;
}

Citizen CreatePrisoner(Citizen prisoner)
{
	prisoner.SetName("Prisoner");
	prisoner.SetPatience(5);
	prisoner.SetViolentEnd(0);
	prisoner.SetPeaceEnd(0);
	prisoner.SetCitizenType("information");

	return prisoner;
}

Citizen CreateMayor(Citizen mayor)
{
	mayor.SetName("Mayor");
	mayor.SetPatience(1);
	mayor.SetViolentEnd(0);
	mayor.SetPeaceEnd(0);
	mayor.SetCitizenType("information");

	return mayor;
}

Vendor CreateShopkeep(Vendor shopkeep)
{
	shopkeep.SetName("Shopkeeper");
	shopkeep.SetPatience(1);
	shopkeep.SetViolentEnd(0);
	shopkeep.SetPeaceEnd(1);
	shopkeep.SetShopType("general store");
	shopkeep.SetItem("Hoard Key");

	return shopkeep;
}

Vendor CreateBlacksmith(Vendor blacksmith)
{
	blacksmith.SetName("Blacksmith");
	blacksmith.SetPatience(1);
	blacksmith.SetViolentEnd(1);
	blacksmith.SetPeaceEnd(0);
	blacksmith.SetShopType("smithy");
	blacksmith.SetItem("Armory Key");

	return blacksmith;
}

Vendor CreateBarkeep(Vendor barkeep)
{
	barkeep.SetName("Barkeepers");
	barkeep.SetPatience(0);
	barkeep.SetViolentEnd(0);
	barkeep.SetPeaceEnd(0);
	barkeep.SetShopType("smithy");
	barkeep.SetItem("Map");
	
	return barkeep;
}

Minion CreateMinionGuard(Minion guard)
{
	guard.SetName("Minion Guard");
	guard.SetPatience(5);
	guard.SetViolentEnd(0);
	guard.SetPeaceEnd(0);
	guard.SetMinionType("guard");
	guard.SetOnDuty("On Duty");

	return guard;
}

Minion CreateMinionServant(Minion servant)
{
	servant.SetName("Minion Servant");
	servant.SetPatience(2);
	servant.SetViolentEnd(0);
	servant.SetPeaceEnd(0);
	servant.SetMinionType("servant");
	servant.SetOnDuty("On Duty");

	return servant;
}

Dragon CreateDragonLord(Dragon lord)
{
	lord.SetName("Dragon");
	lord.SetPatience(5);
	lord.SetViolentEnd(0);
	lord.SetPeaceEnd(0);
	lord.SetDragonType("Boss");

	return lord;
}

Dragon CreateDragonWife(Dragon wife)
{
	wife.SetName("Female Dragon");
	wife.SetPatience(5);
	wife.SetViolentEnd(0);
	wife.SetPeaceEnd(2);
	wife.SetDragonType("information");
	wife.SetSpokeWith(false);

	return wife;
}

Dragon CreateDragonChild(Dragon child)
{
	child.SetName("Dragon Child");
	child.SetPatience(5);
	child.SetViolentEnd(0);
	child.SetPeaceEnd(0);
	child.SetDragonType("information");

	return child;
}