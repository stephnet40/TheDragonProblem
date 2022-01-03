#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "PlayerOptions.h"
#include "ThroneRoomActions.h"

/*
* Name:  Stephanie Thompson
* Date:  07/26/2021
* Email: srthompson5@dmacc.edu
* Description: Final project for C++. A text-based adventure game that uses: If-Then-Else statements, Switch statements, logical operators,
*			   two types of loops (do-while and while), arrays, pass by references, a struct, a class and child classes, and functions.
*/

using namespace std;

int main()
{
	// Arrays and variables needed to change arrays
	string loc[5][6];
	string changeLoc[5][6];
	string locDescript[5][6];
	int x = 2;
	int y = 0;

	// Locations by grid
	loc[2][0] = "at the town entrance";
	loc[3][0] = "at the blacksmith";
	loc[1][1] = "in a village neighborhood";
	loc[2][1] = "at the town square";
	loc[3][1] = "in the market";
	loc[4][1] = "in the tavern";
	loc[2][2] = "at the town exit";
	loc[3][2] = "in the general store";
	loc[1][3] = "in the dungeon";
	loc[2][3] = "at the lair entrance";
	loc[3][3] = "in the kitchen";
	loc[0][4] = "in the armory";
	loc[1][4] = "in the side hall";
	loc[2][4] = "in the main hall";
	loc[3][4] = "at the dragon's hoard";
	loc[4][4] = "in the library";
	loc[1][5] = "in the minion's quarters";
	loc[2][5] = "in the throne room";
	loc[3][5] = "in the dragon's private chambers";

	// Blurbs describing the next location the player has chosen
	changeLoc[2][0] = "back to the entrance of town.";
	changeLoc[3][0] = "entering the town smithy.";
	changeLoc[1][1] = "towards a group of modest homes.";
	changeLoc[2][1] = "entering the center of town.";
	changeLoc[3][1] = "to where most of the activity seems to be.";
	changeLoc[4][1] = "into the local tavern.";
	changeLoc[2][2] = "towards the town exit at the base of the mountain.";
	changeLoc[3][2] = "into the small general store.";
	changeLoc[1][3] = "down into the damp basement of the lair.";
	changeLoc[2][3] = "towards the intimidating gate of the lair.";
	changeLoc[3][3] = "towards the south room, following some rather interesting smells.";
	changeLoc[0][4] = "into what looks like a trophy room.";
	changeLoc[1][4] = "into a hallway that leads to a smaller hall.";
	changeLoc[2][4] = "into the large entry hall.";
	changeLoc[3][4] = "into a room full of gold and jewels.";
	changeLoc[4][4] = "into a rather cozy looking room.";
	changeLoc[1][5] = "into a modest living area.";
	changeLoc[2][5] = "into the throne room, where the dragon awaits.";
	changeLoc[3][5] = "into what seems to be a private area.";

	// Location descriptions
	locDescript[2][0] = "Barrels, crates, and empty wagons have been left unattended by a small building. A trading post, maybe.\nA town guard stands at attention by the town gate.";
	locDescript[3][0] = "The building is filled with a stifling heat. The forge isn't inside, is it?\nWeapons, armor, and farm tools are on display on the walls and racks.\nA gruff man stares at you as you come in. You think it might be best to stay on his good side.";
	locDescript[1][1] = "The houses are modest and cozy. It's clear the town has a close-knit community.\nA man stands near the largest building, acting all important. Ah, that must be the mayor.";
	locDescript[2][1] = "The center of town is an open garden, complete with a beautifully made town well. Buildings create a well kept circular border. Not much of a town SQUARE, you think. More of a circle.\nA couple of villagers are lingering in the area. One is huddled under a tree, his clothes in tatters. The other has an angry scowl on her face, pacing not too far from the well.";
	locDescript[3][1] = "The market is bustling. Well, bustling for a small town, anyways. Barrels and boxes are laid about, holding the goods for the businesses. Several citizens are doing their shopping, seemingly ignoring your presence. One woman catches your eye. She seems worried about something.\nThere's some notable places: a general store, a smithy, and a tavern. All good places for adventurers.";
	locDescript[4][1] = "The tavern smells of alcohol and filled with the sounds of drunken chatter. These people like to start early, you think. It's only noon!";
	locDescript[2][2] = "The exit out of town that leads towards the mountain is rather empty. A lone guard stands in the area, looking like he'd rather be anywhere else.";
	locDescript[3][2] = "The general store is small, but full of useful items. The shopkeeper behind the counter looks at you with a large smile.";
	locDescript[1][3] = "The air is stale and smells of...well, some not so great things. A lone prisoner sits in a nearby cell, playing with some small object. The dungeon guard stares at you, daring you to try something.";
	locDescript[2][3] = "The lair is a large stone castle build into the side of the mountain. It's rather intimdating. So intimidating that only a single guard is needed to scare people away.";
	locDescript[3][3] = "The room is a kitchen filled with both delicious smells and some not so delicious smells. You wonder what dragons eat that requires a kitchen.\nA servant is running around, preparing some dish.";
	locDescript[0][4] = "This isn't a trophy room, it's an armory! Weapons of all shapes, sizes, and quality are just sitting here for the taking.";
	locDescript[1][4] = "This side hall is much smaller than the main one, full of couches, chairs, and cabinets. The castle-version of a living room, perhaps?\nA couple of servants are cleaning the furniture, but they don't pay you any mind.";
	locDescript[2][4] = "The main hall of the lair is cavernous, literally. Half of it is made from the castle walls while the other has been carved out from the moutain.\nA servant is walking through the hall, eyeing you suspiciously.";
	locDescript[3][4] = "You've heard of dragons hoarding treasure, but you never though you'd actually get to see it! Piles of gold and jewels are spread haphazardly around the room, covering furniture. You might never get the oppurtunity to see something like this again.";
	locDescript[4][4] = "Bookshelves cover the wall and a fireplace roars at the end of the room. Plush chairs and rugs are spread throughout the room. It's nice but doesn't seem much used to a dragon.\nA servant is organizing one of the bookshelves.";
	locDescript[1][5] = "The room seems to be a communal area for the servants and guards. Off-duty minions are sitting at tables or taking naps on stiff couches. Some of them glance at you as you enter, but go back to whatever they were doing.";
	locDescript[2][5] = "The throne room isn't as extravagant at you thought, and doesn't even have a throne! It does have, however, a very irritated dragon staring down its snout right at you.";
	locDescript[3][5] = "This seems to be the living space for the dragon. Dragon-sized pillows and furniture decorate the space.\nThere's also two dragons: a female (you think, at least; you're not a dragon expert here) and small, clearly young dragon. It seems the dragon has a family";

	// Characters
	

	string currLoc = loc[x][y];
	string currLocDescript = locDescript[x][y];
	string playerDirection;
	string nextLocation;
	string continuePlaying = "y";
	string playerDecision;
	string encounterResult;
	string endingResult;
	bool gameComplete = false;
	bool lairGuardDefeated = false;
	bool hoardUnlocked = false;
	bool armoryUnlocked = false;
	bool cellUnlocked = false;
	bool dealtMainServant = false;
	int playerChoice;
	int violentEnd = 0;
	int peaceEnd = 0;
	int totalGold = 25;
	int numLootStolen = 0;
	int totalInfamy = 0;  // use as catch-all for determining gameover & force conversation end conditions

	int entryBarrelGold = 10;
	int homeBarrelGold = 15;
	int marketBarrelGold = 50;

	// Game Intro
	
	cout << "You are a traveler looking for adventure and problems to solve." << endl;
	cout << "This small town looks like the perfect place to start." << endl;
	cout << "To choose an action, enter the corresponding number." << endl;
	cout << "Starting Gold: " << totalGold;
	cout << endl;

	// Game Loop
	while (gameComplete == false)
	{
		// Town Entrance
		if (x == 2 && y == 0)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				EntranceAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachGuard();
						do
						{
							TalkToEntryGuard();
							cin >> playerChoice;
							cout << endl;

							switch (playerChoice)
							{
							case 1:
								EntryAskTown();
								break;
							case 2:
								EntryAskRumors();
								break;
							case 3:
								totalInfamy = EntryInsult();
								if (totalInfamy > entryGuard.GetPatience())
								{
									continuePlaying = ContinueGame("game over");
									if (continuePlaying == "y" || continuePlaying == "Y")
									{
										main();
									}
									else
									{
										gameComplete = true;
										playerChoice = 4;
									}
								}
								break;
							case 4:
								LeaveEntryConversation();
								break;
							default:
								ClearInput();
							}

						} while (playerChoice != 4);
						break;
					case 2:
						ExamineEntryBarrel(entryBarrelGold, totalGold, numLootStolen);
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 5:
						LeaveTown();
						continuePlaying = ContinueGame("game over");

						if (continuePlaying == "y" || continuePlaying == "Y")
						{
							main();
						}
						else
						{
							gameComplete = true;
						}
						break;
					
					default:
						ClearInput();
				}

			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3);
		}

		// Town Square
		if (x == 2 && y == 1)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				TownSquareAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachBeggar();
						do
						{
							TalkToBeggar();
							cin >> playerChoice;
							cout << endl;

							switch (playerChoice)
							{
								case 1:
									BeggarAskRumors();
									break;
								case 2:
									BeggarAskStrange();
									break;
								case 3:
									totalInfamy = BeggarInsult(totalGold);
									if (totalInfamy > beggar.GetPatience())
									{						
										playerChoice = 4;
									}
									break;
								case 4:
									LeaveBeggarConversation();
									break;
								default:
									ClearInput();
									break;
							}

						} while (playerChoice != 4);
						break;
					case 2:
						ApproachAngryCitizen();
						do
						{
							TalkToAngryCitizen();
							cin >> playerChoice;
							cout << endl << endl;

							switch (playerChoice)
							{
							case 1:
								AngryAskProblem();
								break;
							case 2:
								AngryAskDragon(violentEnd);
								break;
							case 3:
								totalInfamy = AngryInsult();
								if (totalInfamy > angryCitizen.GetPatience())
								{
									continuePlaying = ContinueGame("game over");
									if (continuePlaying == "y" || continuePlaying == "Y")
									{
										main();
									}
									else
									{
										gameComplete = true;
										playerChoice = 5;
									}
								}
								break;
							case 4:
								AngryLeaveConversation();
								break;
							default:
								ClearInput();
								break;
							}

						} while (playerChoice != 4);
						break;
					case 3:
						ApproachWell(drink);
						break;
					case 4:
						DisplayInventory();
						break;
					case 5:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 6:
						x++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 7:
						x--;
						playerDirection = "west";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 8:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3 || playerChoice == 4);
		}

		// Residential Area
		if (x == 1 && y == 1)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				ResidentialAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachMayor();
						do
						{
							TalkToMayor();
							cin >> playerChoice;
							cout << endl;

							switch (playerChoice)
							{
							case 1:
								MayorAskDragon();
								break;
							case 2:
								MayorAskProblems();
								break;
							case 3:
								totalInfamy = MayorInsult(totalGold);
								if (totalInfamy > mayor.GetPatience())
								{
									playerChoice = 4;
								}
								break;
							case 4:
								LeaveMayorConversation();
								break;
							default:
								ClearInput();
								break;
							}

						} while (playerChoice != 4);
						break;
					case 2:
						ApproachHome(totalInfamy, totalGold, numLootStolen);			
						if (totalInfamy == 1)
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y" || continuePlaying == "Y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 5;
							}
						}
						break;
					case 3:
						ExamineHomeBarrel(homeBarrelGold, totalGold, numLootStolen);						
						break;
					case 4:
						DisplayInventory();
						break;
					case 5:
						x++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3 || playerChoice == 4);
		}

		// Market
		if (x == 3 && y == 1)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				MarketAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachConcernedCitizen(peaceEnd);
						break;
					case 2:
						ExamineMarketBarrel(marketBarrelGold, totalGold, numLootStolen);
						break;
					case 3:
						totalInfamy = PickpocketCitizen(totalGold, numLootStolen);
						if (totalInfamy == 1)
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y" || continuePlaying == "Y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 5;
							}
						}
						break;
					case 4:
						DisplayInventory();
						break;
					case 5:
						x++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 6:
						y++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 7:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 8:
						x--;
						playerDirection = "west";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3 || playerChoice == 4);
		}
	
		// Tavern
		if (x == 4 && y == 1) 
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				TavernAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachBarkeep(totalGold, totalInfamy, map, food);
						if (totalInfamy > barkeep.GetPatience())
						{
							x--;
							playerChoice = 3;
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						x--;
						ExitBuilding();
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}
		
		// General Store
		if (x == 3 && y == 2)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				GeneralStoreAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachShopkeep(totalGold, totalInfamy, hoardKey, toy, peaceEnd);
						if (totalInfamy > shopkeep.GetPatience())
						{
							y--;
							playerChoice = 3;
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						y--;
						ExitBuilding();
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}
		
		// Smithy
		if (x == 3 && y == 0)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);
	
			do
			{
				BlacksmithAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachBlacksmith(totalGold, totalInfamy, armoryKey, weapon, violentEnd);
						if (totalInfamy > blacksmith.GetPatience())
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y" || continuePlaying == "Y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 3;
							}
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						y++;
						ExitBuilding();
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}
		
		// Town Exit
		if (x == 2 && y == 2)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				ExitAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachGuard(totalInfamy);
						if (totalInfamy > exitGuard.GetPatience())
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y" || continuePlaying == "Y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 3;
							}
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					case 4:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}

		// Lair Entrance
		if (x == 2 && y == 3)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);
			do
			{
				LairEntryAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						EncounterEntryMinion(encounterResult);
						if (encounterResult == "success")
						{
							y++;
						}
						else if (encounterResult == "return to town")
						{
							y--;
						}
						else
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y" || continuePlaying == "Y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 3;
							}
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeArea(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				} 
			} while (playerChoice == 2);
		}

		// Main Hall
		if (x == 2 && y == 4)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				MainHallAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						EncounterMainServant(totalInfamy, dealtMainServant);
						if (totalInfamy > 0)
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 0;
							}
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						OpenThroneRoom(throneKey);
						if (throneKey.inInventory == true)
						{
							y++;
							playerDirection = "north";
							nextLocation = changeLoc[x][y];
							ChangeRoom(playerDirection, nextLocation);
						}
						else
						{
							playerChoice = 1;
						}
						break;
					case 4:
						if (hoardUnlocked == true)
						{
							x++;
							playerDirection = "east";
							nextLocation = changeLoc[x][y];
							ChangeRoom(playerDirection, nextLocation);
						}
						else
						{
							OpenHoard(hoardKey, hoardUnlocked);
							if (hoardKey.inInventory == true)
							{
								x++;
							}
							else
							{
								playerChoice = 1;
							}
						}
						break;
					case 5:
						x--;
						playerDirection = "west";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2); 
		}

		// Side Hall
		if (x == 1 && y == 4)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				SideHallAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						EncounterSideServant(totalInfamy);
						if (totalInfamy > minionServant.GetPatience())
						{
							continuePlaying = ContinueGame("game over");
							if (continuePlaying == "y")
							{
								main();
							}
							else
							{
								gameComplete = true;
								playerChoice = 4;
							}
						}
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						if (armoryUnlocked == true)
						{
							x--;
							playerDirection = "west";
							nextLocation = changeLoc[x][y];
							ChangeRoom(playerDirection, nextLocation);
						}
						else
						{
							OpenArmory(armoryKey, armoryUnlocked);
							if (armoryKey.inInventory == true)
							{
								x--;
							}
							else
							{
								playerChoice = 1;
							}
						}
						break;
					case 4:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					case 5:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);;
						break;
					case 6:
						x++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);;
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2); // Add new condition for locked door
		}

		// Dungeon
		if (x == 1 && y == 3)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				DungeonAction();
				cin >> playerChoice;

				bool foughtGuard = false;
				bool bribedGuard = false;

				switch (playerChoice)
				{
					case 1:
						EncounterDungeonGuard(totalInfamy, foughtGuard, bribedGuard);
						break;
					case 2:
						ApproachPrisoner();
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						if (cellUnlocked == true)
						{
							CellUnlocked();
						}
						else
						{
							UnlockCell(totalInfamy, foughtGuard, bribedGuard, cellUnlocked);
						}
						break;
					case 5:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while ((playerChoice == 1 || playerChoice == 2 || playerChoice == 3 || playerChoice == 4) && totalInfamy == 0);

			if (totalInfamy > 0)
			{
				continuePlaying = ContinueGame("game over");
				if (continuePlaying == "y")
				{
					main();
				}
				else
				{
					gameComplete = true;
				}
			}
		}

		// Armory
		if (x == 0 && y == 4)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				ArmoryAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ExamineWeapons(weapon);
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						x++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}

		// Minion Quarters
		if (x == 1 && y == 5)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				MinionQuartersAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachOffDutyMinion();
						break;
					case 2:
						StealSleepingMinion(throneKey);
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3);
		}

		// Hoard
		if (x == 3 && y == 4)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				HoardAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ExamineTreasure();
						break;
					case 2:
						DisplayInventory();
						break;
					case 3:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					case 4:
						x++;
						playerDirection = "east";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					case 5:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					case 6:
						x--;
						playerDirection = "west";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2);
		}

		// Kitchen
		if (x == 3 && y == 3)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				KitchenAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachKitchenServant(totalInfamy);
						if (totalInfamy > minionServant.GetPatience())
						{
							y++;
							playerChoice = 4;
						}
						break;
					case 2:
						ExamineIngredients();
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						y++;
						playerDirection = "north";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3);
		}

		// Library
		if (x == 4 && y == 4)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				LibraryAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachLibraryServant();
						break;
					case 2:
						ExamineBooks();
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						x--;
						playerDirection = "west";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);;
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3);
		}

		// Private Chamber
		if (x == 3 && y == 5)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				PrivateChambersAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						ApproachFemaleDragon(throneKey, dragonWife, peaceEnd);
						break;
					case 2:
						ApproachYoungDragon(toy);
						break;
					case 3:
						DisplayInventory();
						break;
					case 4:
						y--;
						playerDirection = "south";
						nextLocation = changeLoc[x][y];
						ChangeRoom(playerDirection, nextLocation);
						break;
					default:
						ClearInput();
				}
			} while (playerChoice == 1 || playerChoice == 2 || playerChoice == 3);
		}

		// Throne Room
		if (x == 2 && y == 5)
		{
			currLoc = loc[x][y];
			currLocDescript = locDescript[x][y];
			CurrentLocation(currLoc, currLocDescript);

			do
			{
				ThroneRoomAction();
				cin >> playerChoice;

				switch (playerChoice)
				{
					case 1:
						endingResult = ConfrontDragon(peaceEnd, violentEnd);
						break;
					case 2:
						AttemptToLeave();
						break;
					default:
						ClearInput();
				}
			} while (playerChoice != 1);

			continuePlaying = ContinueGame(endingResult);
			if (continuePlaying == "y")
			{
				main();
			}
			else
			{
				gameComplete = true;
			}
		}
	}
	
	return 0;
}

