// Game.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"
#include <string>
//#include "windows.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//***** DEFINES VARIABLES *****
bool repeat, turn, rep = true;
char type = 0;
string what = "";
int tutorRep, userChoice, swear, reload = 0;
int gold = 0;
//char charAr[8], typeAr[8] = 0;
//string typeStr;
string reserve, attack, opReserve, opAttack, attChoice, opTurnChoice;
string name = "";
string swearAr[4] = { "FUCK", "SHIT", "BITCH", "HELL" };
float res, att, heal, def, spec, opRes, opResMax, opAtt, opHeal, opDef, opSpec = 0;
int attRound, opAttRound = 0;
int specAtt, opSpecAtt, opTurn;
int intAttacks = 0;
bool hax = false;
double encounters, fear, attacks, kills, stissKills, stissEncounters, killedStiss, gusKills, gusEncounters = 0;
string reluctance, expStr = "";
// JUSTICE -> GUS + STISS; ARMISTICE -> AMISS + STISS 
bool stissAlive, stissLike, gusAlive = true;
bool boss, pacifist = false;
int level, opLevel, experience, expGive = 0;
/* levelAr:
levelAr[0] == health
levelAr[1] == defense
levelAr[2] == attack
*/
float levelAr[3] = { 0, 0, 0 };
float choice, opChoice, defChoice, opDefChoice;
float randomRound;
int randomDef, defI = 0;
string monst, phrase;
bool ded = false;

//***** DEFINES FUNCTIONS *****
string pickMonst(string &);
void monstDefinition(string);
void levelUp();
void giveExp();
void monstOut();
void bossOut(string);
void stissAtt();
void bossBattle(string);
void whichSwitch(string);
void battle();
void battleProcess();
void isDed();
void levelOne();
void levelTwo();
void levelThree();
void levelFour();

//void is used so I don’t need return 0 after my function (int used, ignore comment)

//***** INITILIZATION FUNCTION *****
void initialization()
{
	cout << "Character initializing\n";
	//    Sleep(500);
	//following looks like a person
	//    Sleep(500);
	cout << "  o  \n";
	//    Sleep(500);
	cout << " \\|/ \n";
	//    Sleep(500);
	cout << " / \\ \n";
	//    Sleep(500);
	cout << "Character initialized \n\n";
	//    Sleep(500);
	cout << "Hello adventurer. I will be your guide.\n";
	//if a class is chosen, the do will stop, but if not, the do will keep going
	do
	{
		repeat = false;
		cout << "Please choose a class, Fighter, Mage, Archer, or Lawyer.\n";
		getline(cin, name, '\n');
		for (int i = 0; i < name.length(); i++)
		{
			name[i] = toupper(name[i]);
		}

		if (name.find("FIGHTER", 0) != -1)
		{
			cout << "You have chosen FIGHTER\n";
			type = 'F';
		}
		else if (name.find("MAGE", 0) != -1)
		{
			cout << "You have chosen MAGE\n";
			type = 'M';
		}
		else if (name.find("ARCHER", 0) != -1)
		{
			cout << "You have chosen ARCHER\n";
			type = 'A';
		}
		else if (name.find("LAWYER", 0) != -1)
		{
			cout << "You have chosen SCUMBAG\n";
			cout << "I mean LAWYER\n";
			type = 'L';
		}
		else if (name == "MLG360NOSCOPE")
		{
			cout << "2 dank 4 u!!!" << endl;
		}
		else if (name == "PULKIT")
		{
			cout << "Shut up, this is my cross x" << endl;
		}
		else if (name == "AARUSH")
		{
			cout << "AARRRRRRUUUUUUUUSSSSSSHHHH \nFirst, I'd like to call abuse in my 1AR" << endl;
		}
		else if (name == "AMOGH")
		{
			cout << "Federalism DA!!" << endl;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				swear = name.find(swearAr[j], 0);
				if (swear != -1)
				{
					j = 4;
				}
			}
			if (swear == -1)
			{
				cout << "Screw you... actually type a class now\n\n";
				repeat = true;
				userChoice++;
				if (userChoice == 3)
				{
					cout << "I'll just make u a generic class" << endl;
					reserve = "Reserve";
					attack = "ATTACK";
					repeat = false;
				}
				//            Sleep(500);
			}
			else
			{
				cout << "\nDid u swear @ me???\nU should kill ur self\nActually, I'll do it for you\nU ded\n" << endl;
				exit(0);
				ded = true;
			}
		}
	} while (repeat == true);
	//ignores all characters in type until it gets to the enter character (which is entered after every cin)
//	cin.ignore(type, '\n');
	//press any key to continue
	system("PAUSE");
	cout << endl;
	//clears the console
	system("CLS");

	//***** INITIALIZATION SCREEN TWO *****
	//screen 2
	heal = 10;
	def = 1;
	att = 1;
	specAtt = att * 10;

	if (type == 'L' || type == 'F')
	{
		cout << "Your class is a close ranged class. \n\n";
		cout << "This is your weapon:\n\n";
	}
	else if (type == 'M' || type == 'A')
	{
		cout << "Your class is a long ranged class. \n\n";
		cout << "This is your weapon:\n\n";
	}
	res = 10 + level;
	switch (type)
	{
		//prints sword
	case 'F':
		reserve = "Energy";
		attack = "SWORD SWING";
		levelAr[0] = 20;
		levelAr[1] = 1.5;
		levelAr[2] = 1.5;
		cout << "         / \\\n        /   \\\n       /  \\  \\\n       |  |  |\n       |  |  |\n       |  |  |\n       |  |  |\n       |  |  |\n       |  |  |\n       |  |  |\n       |  /  |\n ______|_____|______\n/                   \\\n\\___________________/\n       |     |\n       |     |\n       /     \\\n       |     |\n       \\_____/\n\n";
		break;	

		//prints staff
	case 'M':
		reserve = "Mana";
		attack = "FIREBALL";
		levelAr[0] = 25;
		levelAr[1] = 1;
		levelAr[2] = 1.5;
		cout << "        ______\n     / ________ \\\n    / __________ \\\n   |/|    <>    |\\|\n   |\\|__________|/|\n    \\ __________ /\n     \\ ________ /\n         |__|\n         |__|\n         |  |\n         |  |\n         |  |\n         |  |\n         |__|\n         |__|\n         |  |\n         |__|\n         /  \\\n         \\__/\n\n";
		break;

		//prints bow
	case 'A':
		reserve = "Arrows";
		attack = "SHOT";
		levelAr[0] = 10;
		levelAr[1] = 1.5;
		levelAr[2] = 2.5;
		cout << "||\\\\\\\n||  \\\\\\\\\n||    \\\\\\\\\n||      \\\\\\\\\n||        \\\\\\\n||          \\\\\\\n||           \\\\\\\n||            \\\\\\\n||             \\\\\\\n||             |||)\n||             ///\n||            ///\n||           ///\n||          ///\n||        ///\n||      ////\n||    ////\n||  ////\n||///\n\n";
		break;

	case 'L':
		reserve = "Evidence";
		attack = "CROSS EXAMINATION";
		levelAr[0] = 15;
		levelAr[1] = 1.5;
		levelAr[2] = 1.5;
		cout << "___________________\n\\    <~~~~~~~~~~>   \\\n \\ ~~~~~~~~~~~~~~~~~ \\\n  \\ ~~~~~~~~~~~~~~~~~ \\\n   \\ ~~~~~~~~~~~~~~~~~ \\\n    \\ ~~~~~~~~~~~~~~~~~ \\\n     \\ ~~~~~~~~~~~~~~~~~ \\\n      \\ ~~~~~~~~~~~~~~~~~ \\\n       \\ ~~~~~~~~~~~~~~~~~ \\\n        \\___________________\\\n\n";
		break;
	}

	//***** SPECIAL CLASSES *****
	if (name == "MLG360NOSCOPE")
	{
		reserve = "Lol noscops";
		attack = "QUIKSCOPS";
		levelAr[0] = 999;
		levelAr[1] = 600;
		levelAr[2] = 320;
		def = 311;
		att = 100;
		cout << "420 weeeeeeed\nU has super long ranged class\nSmoke past tha competition sukas!!!\n" << endl;
	}
	else if (name == "PULKIT")
	{
		cout << "PK manz are great!!!" << endl;
		reserve = "Common knowledge";
		attack = "EXTRA SENSUAL PLEASURE";
		levelAr[0] = 777;
		levelAr[1] = 888;
		levelAr[2] = 999;
		def = 10;
		att = 11;
	}
	else if (name == "AARUSH")
	{
		cout << "WTF are you doing with your lyfe r/n?? Srsly." << endl;
		reserve = "1ARz left";
		attack = "ABUSE";
		levelAr[0] = 750;
		levelAr[1] = 1000;
		levelAr[2] = 1250;
		def = 100;
		att = 110;
	}
	else if (name == "AMOGH")
	{
		cout << "*dab*dab*dab*dab*dab*dab*dab*dab*dab*dab*\n*huff* *huff*\n*dab*dab*dab*dab*dab*dab*dab*dab*dab*dab*" << endl;
		reserve = "Memz";
		attack = "OUTD8TED M3M3Z";
		levelAr[0] = 9001;
		levelAr[1] = 9001;
		levelAr[2] = 9001;
		def = 9001;
		att = 9001;
	}
	else if (userChoice == 3)
	{
		levelAr[0] = 1;
		levelAr[1] = 1;
		levelAr[2] = 1;
		cout << "Other classes get cool text and weapon images, u suk, so u don't\n" << endl;
	}
	system("PAUSE");
	cout << endl;
	system("CLS");
}

//***** USER SPECIAL ATTACK *****
void specialAttInt()
{
	if (spec == 10)
	{
		choice = specAtt;
		spec = 0;
	}
	else
	{
		choice = att;
	}
}

//***** OPPONENT SPECIAL ATTACK *****
void opSpecialAttInt()
{
	if (opSpec == 10)
	{
		opChoice = opSpecAtt;
		opSpec = 0;
	}
	else
	{
		opChoice = opAtt;
	}
}

//***** USER DEFENSE *****
void defend(int random)
{
	opAttRound = opChoice;
	srand(defI);
	random = (rand() % (opAttRound + 1));
	random += def - 1;
	//input
	if (random > 0 && random < opChoice)
	{
		randomRound = random;
		heal += randomRound;
	}
	else if (random >= opChoice)
	{
		randomRound = opChoice;
		heal += randomRound;
	}
	else
	{
		randomRound = 0;
		cout << "Defense fail\n";
	}

	//output
	if (opAttRound == opChoice)
	{
		cout << "You defended yourself from " << randomRound << " damage" << endl;
	}
	else if (randomRound > 0 && randomRound != opChoice)
	{
		opHeal += 0.5;
		cout << "You defended yourself from " << randomRound + 0.5 << " damage" << endl;
	}
	else
	{
		cout << "You defended yourself from " << randomRound << " damage" << endl;
	}
	defI++;
}

//***** OPPONENT DEFENSE *****
void opDefend(int random)
{
	attRound = choice;
	srand(defI);
	random = rand() % (attRound + 1);
	random += opDef - 1;
	//input
	if (random > 0 && random < choice)
	{
		randomRound = random;
		opHeal += randomRound;
	}
	else if (random >= choice)
	{
		randomRound = choice;
		opHeal += randomRound;
	}
	else
	{
		randomRound = 0;
		cout << "Defense fail\n";
	}

	//output
	if (attRound == choice)
	{
		cout << "Opponent defended themself from " << randomRound << " damage" << endl;
	}
	else if (randomRound > 0 && randomRound != choice)
	{
		opHeal += 0.5;
		cout << "Opponent defended themself from " << randomRound + 0.5 << " damage" << endl;
	}
	else
	{
		cout << "Opponent defended themself from " << randomRound << " damage" << endl;
	}
	cout << endl;
	defI++;
}

//***** USER BATTLE INFORMATION *****
void battleInfo()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "-----------YOU-----------\n";
	cout << "Level: " << level << endl;
	cout << "Charge: " << spec << "/10" << endl;
	cout << reserve << ": " << res << endl;
	cout << "Health: " << heal << endl;
	cout << "=========================\n";
}

//***** USER ATTACK *****
void attDialogue()
{
	attChoice = "";
	choice = 0;
	defChoice = 0;
	cout << "What would you like to do?\n";
	what = "";
	getline(cin, what, '\n');

	for (int m = 0; m < what.length(); m++)
	{
		what[m] = toupper(what[m]);
	}

	if (what.find("ATT", 0) != -1)
	{
		if (res > 0)
		{
			specialAttInt();
			res--;
			attChoice = "ATTACK";
			attacks++;
			opHeal -= choice;
		}
		else
		{
			attChoice = "ATTACK, but you are out of " + reserve;
		}
	}
	else if (what.find("DEF", 0) != -1)
	{
		attChoice = "DEFEND";
		if (res < 10 + level)
		{
			res++;
		}
		defChoice = 1;
	}
	else if (what.find("SPARE", 0) != -1 && boss == false)
	{
		attChoice = "SPARE";
		expGive = 49 * opLevel + 1;
		intAttacks = attacks;
		switch (intAttacks)
		{
		case 0:
			reluctance = "happily";
			break;
		case 1:
			reluctance = "hesitated, but";
			fear += 1;
			break;
		case 2:
			reluctance = "grudginly";
			fear += 2;
			break;
		case 3:
			reluctance = "astonishedly";
			fear += 3;
			break;
		case 4:
			reluctance = "reluctantly";
			fear += 4;
			break;
		case 5:
			reluctance = "sadly";
			fear += 5;
			break;
		default:
			reluctance = "fEaRfUlLy";
			fear += 10;
			break;
		}
		expStr = monst + " " + reluctance + " gave you ";
		kills--;
		opHeal = 0;
	}
	else if (what.find("SPARE", 0) != -1 && boss == true)
	{
		if (monst == "STISS")
		{
			if (kills == encounters)
			{
				attChoice = "SPARE, but were rejected";
				cout << "I WILL NOT LET YOU 'spare' ME YOU MURDERER" << endl;
				opDefChoice = 5;
			}
			else if (kills > 0)
			{
				if (fear / encounters > 0.5)
				{
					attChoice = "SPARE, but were rejected";
					cout << "YOU TORTURED MONSTERS BEFORE YOU SPARED THEM\nI WILL NOT LET YOU 'spare' ME" << endl;
					opDefChoice = 5;
				}
				else
				{
					cout << "OKAY... JUST REMEMBER TO KEEP SPARING\nAND DON'T HURT THE MONSTERS BEFORE YOU SPARE THEM" << endl;
					expStr = "STISS gladly gave you ";
					kills--;
					opHeal = 0;
				}
			}
			else
			{
				if (fear / encounters > 0.5)
				{
					attChoice = "SPARE, but were rejected";
					cout << "YOU TORTURED MONSTERS BEFORE YOU SPARED THEM\nI WILL NOT LET YOU 'spare' ME" << endl;
					opDefChoice = 5;
				}
			}
		}
	}
	else if (what.find("KMS", 0) != -1)
	{
		hax = false;
		attChoice = "kill urself";
		heal = 0;
	}
	else
	{
		attChoice = "BIDE";
		if (spec < 10)
		{
			spec++;
		}
	}
	cout << "You chose to " << attChoice << endl;
	if (choice != 0)
	{
		cout << "You dealt " << choice << " damage with your " << attack << endl;
	}
	else if (defChoice == 1 && opTurn == 1)
	{
		defend(randomDef);
	}
	turn = false;
	cout << endl;
	system("PAUSE");
	cout << endl;
}

//***** OPPONENT ATTACK *****
void opDialogue()
{
	turn = true;
	opDefChoice = 0;
	opTurn = rand() % 3 + 1;
	if (opTurn == 1)
	{
		if (opRes > 0)
		{
			opSpecialAttInt();
			opRes--;
			opTurnChoice = "ATTACK";
			rep = true;
		}
		else
		{
			turn = false;
		}
	}
	else if (opTurn == 2)
	{
		if (opRes < opResMax)
		{
			opTurnChoice = "DEFEND";
			opRes++;
			rep = true;
			opDefChoice = 1;
		}
		else
		{
			turn = false;
		}
	}
	else if (opTurn == 3)
	{
		if (opSpec < 10)
		{
			opTurnChoice = "BIDE";
			opSpec++;
			rep = true;
		}
		else
		{
			turn = false;
		}
	}
	if (turn == true)
	{
		cout << "Opponent chose to " << opTurnChoice << endl;
		if (opTurn == 1)
		{
			cout << "They dealt " << opChoice << " damage!" << endl;
			heal -= opChoice;
			cout << endl;
		}
		else if (opDefChoice == 1 && attChoice == "ATTACK")
		{
			opDefend(randomDef);
		}
		else
		{
			cout << endl;
		}

		if (kills == encounters && level > 1)
		{
			cout << "But now, " << monst << " is paralyzed with fear" << endl;
			cout << "They witnessed you kill " << kills << " creatures" << endl;
			cout << "Their health went down significantally\n" << endl;
		}
		system("PAUSE");
	}
	else
	{
		rep = false;
	}
}

//***** ATTACK SWITCH *****
void attSwitch()
{
	if (ded == false)
	{
		switch (turn)
		{
		case true:
			attDialogue();
			break;
		case false:
			opDialogue();
			break;
		}
	}
	if (heal <= 0)
	{
		heal = 0;
		ded = true;
	}
	else if (opHeal <= 0)
	{
		opHeal = 0;
		ded = true;
	}
}

//***** UNUSED HEAL RESET *****
/*
char healReset(char type)
{
if (type == 'F')
{
heal = 10 + 20 * level;
}
else if (type == 'M')
{
heal = 10 + 25 * level;
}
else if (type == 'A')
{
heal = 10 + 10 * level;
}
else if (type == 'L')
{
heal = 10 + 15 * level;
}
return heal;
}
*/

//***** RESET *****
void reset()
{
	attChoice = "";
	spec = 0;
	opSpec = 0;
	heal = 10 + level * levelAr[0];
	res = 10 + level;
}

//***** WIN OR LOSE DIALOGUE *****
void dialogue(string phrase, string monst)
{
	if (heal == 0)
	{
		cout << "Your health is " << heal << endl;
		cout << "U suk @ life\n";
	}
	else if (opHeal == 0)
	{
		cout << "\n\n\n*****************************************\n" << phrase << " you beat a " << monst << "\n*****************************************\n\n\n" << endl;
		cout << "     *   *\n  *         *\n *     () () *\n *       <   *\n  *         *\n     *   *\n       |    O\n       |   /\n       |  /\n       | /\n       |/\n      /|\n     / |\n     | |\n     | |\n     O |\n      / \\\n     /   \\\n    /     \\\n   /       \\\n  /         \\\n" << endl;

	}
}

//***** DUMMY MONSTER *****
void dummy()
{
	cout << "----------Dummy----------\n";
	cout << "Level 0" << endl;
	cout << "Charge: " << opSpec << "/10" << endl;
	cout << "Reserve: " << opRes << endl;
	cout << "Health: " << opHeal << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << endl;
}

//***** TUTORIAL *****
void tutorial()
{
	cout << "Quick, kill this dummy or we'll all die.\n";
	cout << "Type attack to deal damage, defend to increase reserves and protect from damage.\n";
	cout << "Enter anything to bide, charge up your special ability.\n";
	cout << "Attack with full charge to deal 10X damage.\n";
	monst = "DUMMY";
	opHeal = 11;
	opAtt = 1;
	opSpecAtt = opAtt * 10;
	opDef = 1;
	opRes = 10;
	opResMax = opRes;
	while (ded == false)
	{
		if (rep == true)
		{
			battleInfo();
			dummy();
		}
		attSwitch();
		if (rep == true)
		{
			system("CLS");
		}
	}
	ded = false;
	dialogue("     U dids it...", "DUMMY");
	system("PAUSE");
	cout << endl;
	system("CLS");
	if (heal != 0)
	{
		//		heal = healReset(type);
		levelUp();
		cout << "You did rather poorly fighting that DUMMY... no matter, there are more enemies to fight." << endl << endl;
		encounters++;
		kills++;
		reset();
	}
}

//***** MAIN PROGRAM *****
int main()
{
	srand(time(NULL));
	initialization();
	tutorial();
/*	while (reload != 0)
	{
*/
		while (heal != 0)
		{
			isDed();
		}
/*		cout << "Reload save?" << endl;
		getline(cin, name, '\n');
		for(int i = 0; i < name.length(); i++)
		{
			name [i] = toupper(name[i]);
		}
		if (name.find("NO", 0) != -1)
		{
			reload = 0;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				swear = name.find(swearAr[j], 0);
				if (swear != -1)
				{
					j = 4;
				}
			}
			if (swear == -1)
			{
				cout << "So, I'm guessing you want to replay..." << endl;
				reset();
			}
			else
			{
				cout << "Thanks for swearing at me..." << "\nI'm starting this game over" << endl;
				reload = 0;
			}
		}
		system("PAUSE");
		cout << endl;
		system("CLS");
	}
*/
	return 0;
}

//***** IS DED *****
void isDed()
{
	if (heal != 0)
	{
		switch (level)
		{
		case 1:
			levelOne();
			break;
		case 2:
			levelTwo();
			stissAlive = true;
			break;
		case 3:
			if (killedStiss == 0)
			{
				reset();
				levelThree();
			}
			else
			{
				while (heal > 0 && level < 4)
				{
					battleProcess();
				}
			}
			break;
		case 4:
			levelFour();
			break;
		}
	}
}

//***** BOSS SWITCH *****
void whichSwitch(string boss)
{
	if (ded == false)
	{
		switch (turn)
		{
		case true:
			attDialogue();
			break;
		case false:
			if (boss == "STISS")
			{
				stissAtt();
			}
			break;
		}
	}
	if (heal <= 0)
	{
		heal = 0;
		ded = true;
	}
	else if (opHeal <= 0)
	{
		opHeal = 0;
		ded = true;
	}
}

//***** STISS ATTACK *****
void stissAtt()
{
	opTurnChoice = "";
	opTurn = 0;
	turn = true;
	rep = true;
	if (attChoice == "DEFEND" || opDefChoice == 5 || attChoice == "")
	{
		if (opRes > 0)
		{
			opSpecialAttInt();
			opRes--;
			opTurn = 1;
			opTurnChoice = "ATTACK";
			opDefChoice = 0;
		}
		else
		{
			opTurnChoice = "DEFEND";
			opRes++;
			opDefChoice = 0;
		}
	}
	else if (attChoice == "ATTACK" || opDefChoice == 1)
	{
		opTurnChoice = "DEFEND";
		opRes++;
		opDefChoice = 0;
	}
	else if (attChoice == "BIDE")
	{
		if (opSpec < 10)
		{
			opTurnChoice = "BIDE";
			opSpec++;
		}
		else
		{
			turn = false;
			opDefChoice = 5;
		}
	}

	if (turn == true)
	{
		cout << "STISS chose to " << opTurnChoice << endl;
		if (opTurnChoice == "ATTACK" && heal - opChoice > 0)
		{
			cout << "She dealt " << opChoice << " damage!" << endl;
			heal -= opChoice;
			cout << endl;
		}
		else if (opTurnChoice == "ATTACK" && heal - opChoice <= 0)
		{
			cout << "But she didn't want to kill you" << endl;
			cout << "STISS is sparing you" << endl;
			cout << "What will you do" << endl;
			getline(cin, what, '\n');
			for (int w = 0; w < what.length(); w++)
			{
				what[w] = toupper(what[w]);
			}
			if (what.find("ATT", 0) != -1)
			{
				cout << "You dealt 99999 damage" << endl;
				cout << "YOU AT-ATTACKED... I BUT I UNDERSTAND" << endl;
				phrase = "I UNDERSTAND";
				opHeal = -99999;
				stissAlive = false;
				killedStiss++;
				stissLike = false;
				hax = false;
				system("PAUSE");
				cout << endl;
				system("CLS");
				bossOut(monst);
			}
			else
			{
				expStr = "STISS, in her rage, dropped ";
				cout << "You chose to SPARE" << endl;
				cout << "I SEE MY CHILD..." << endl;
				phrase = "BUT I CAN STILL TELL";
				killedStiss = 0;                                            
				stissAlive = true;
				stissLike = false;
				hax = false;
				opHeal = 0;
				system("PAUSE");
				cout << endl;
				system("CLS");
				bossOut(monst);
			}
		}
		else if (opTurnChoice == "DEFEND" && attChoice == "ATTACK")
		{
			opDefend(randomDef);
		}
		else
		{
			cout << endl;
		}
		system("PAUSE");
	}
	else
	{
		rep = false;
	}
}

//***** LEVEL ONE *****
void levelOne()
{
	cout << "Check back with me when you are level 2." << endl;
	system("PAUSE");
	cout << endl;
	while (heal > 0 && level < 2)
	{
		battleProcess();
	}
}

//**** LEVEL TWO *****
void levelTwo()
{
	cout << "Cool, you're level 2, let's get on to killing more things." << endl;
	system("PAUSE");
	if (kills == encounters)
	{
		cout << "\nYOU HAVE KILLED EVERYTHING YOU HAVE ENCOUNTERED..." << endl;
		cout << "YOU... PLAYER, IF YOU NEED TO KILL, KILL YOURSELF" << endl;
		cout << "LIKE, TYPE KMS TO KILL URSELF (OR U CAN KUIT THA GAME)" << endl;
		getline(cin, name, '\n');
		for (int k = 0; k < name.length(); k++)
		{
			name[k] = toupper(name[k]);
		}
		if (name == "KMS")
		{
			cout << "U ded... u just w8sted ur time on dis game, lol\nGit dunked on!!!" << endl;
			heal = 0;
		}
		else
		{
			cout << "HAVE IT UR WAY... JUST REMEMBER TO spare THESE CREATURES, U DO NOT NEED TO FIGHT THEM\n" << endl;
		}
	}
	else if (kills > 0)
	{
		cout << "\nYOU DO NOT NEED TO KILL..." << endl;
		cout << "I SEE YOU UNDERSTAND THE CONCEPT OF SPARING..." << endl;
		cout << "BUT YOU SHOULD NOT KILL AS MUCH AS YOU DO..." << endl;
		cout << "I WILL LEAVE NOW" << endl;
	}
	else
	{
		cout << "\nDO NOT LISTEN TO HIM" << endl;
		cout << "KEEP UP YOUR SPARING" << endl;
	}
	system("PAUSE");
	cout << endl;
	system("CLS");
	while (heal > 0 && level < 3)
	{
		battleProcess();
	}
}

//**** LEVEL THREE *****
void levelThree()
{
	reset();
	cout << "Kill." << endl;
	if (kills >= encounters)
	{
		cout << "Keep killing... no mercy should be shown." << endl;
	}
	else if (kills > 0)
	{
		cout << "Show no mercy... do not spare even a single thing." << endl;
	}
	else
	{
		cout << "You are not a nice person for sparing everything." << endl;
		cout << "You spare out of curiosity." << endl;
		cout << "But only killing will bring you joy." << endl;
	}
	cout << "Listen to me, your best friend, your guide." << endl;
	system("PAUSE");
	monst = "STISS";
	boss = true;
	phrase = "YO, THE ONLY WAY THAT YOU COULD'VE GOTTEN THIS MESSAGE...\nIS IF YOU'RE A HACKER!\nWELP... I GUESS";
	cout << "\nI TOLD YOU NOT TO KILL..." << endl;
	if (stissKills == stissEncounters)
	{
		cout << "BUT I SEE YOU ALREADY HAVE\nAFTER I WARNED YOU\nEVERYTHING YOU'VE ENCOUNTERED... THEY'VE..." << endl;
		system("PAUSE");
		cout << endl;
		system("CLS");
		battleProcess();
	}
	else if (stissKills > 0)
	{
		cout << "BUT YOU KILLED ANYWAYS" << endl;
		system("PAUSE");
		cout << endl;
		system("CLS");
		battleProcess();
	}
	else
	{
		cout << "AND I THANK YOU FOR LISTENING" << endl;
		if (fear / encounters > 0.5)
		{
			cout << "BUT YOU HURT THEM BEFORE YOU SPARED THEM" << endl;
			cout << "YOU TOYED WITH THEM" << endl;
			system("PAUSE");
			cout << endl;
			system("CLS");
			battleProcess();
		}
		else if (fear / encounters > 0)
		{
			cout << "TRY NOT TO HURT THEM BEFORE SPARING THEM THOUGH" << endl;
			cout << "I'M GOING TO LEAVE NOW\n" << endl;
			cout << "STISS THANKS YOU FOR NOT SPARING" << endl;
			cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ^^^  ^^^ \\\\\n        //  (^)  (^)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\      \\\\\\\\\n        ////// uu \\\\\\\\\\\\   \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\\\n    ////// uuuuuuuuuu //\n    //// \\\\ uuuuuuuu //\n     ///  \\\\________//\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
			system("PAUSE");
			cout << endl;
			system("CLS");
			killedStiss = 0;
			expStr = "STISS hesitantally gave you ";
			attChoice = "SPARE";
			expGive = 100;
			giveExp();
			levelUp();
		}
		else
		{
			cout << "THANK YOU FOR NOT ATTACKING THEM" << endl;
			cout << "HAVE SOME EXP\n" << endl;
			cout << "STISS THANKS YOU FOR NOT ATTACKING" << endl;
			cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ^^^  ^^^ \\\\\n        //  (^)  (^)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\      \\\\\\\\\n        ////// uu \\\\\\\\\\\\   \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\\\n    ////// uuuuuuuuuu //\n    //// \\\\ uuuuuuuu //\n     ///  \\\\________//\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
			system("PAUSE");
			cout << endl;
			system("CLS");
			killedStiss = 0;
			expStr = "STISS happiy gave you ";
			attChoice = "SPARE";
			kills--;
			expGive = 250;
			giveExp();
			levelUp();
		}
	}
	boss = false;

	if (hax == true && heal > 0)
	{
		stissAlive = false;
		killedStiss++;
		if (stissAlive == false)
		{
			cout << "STISS WUZ SHOCKED BY YOUR ATTACK" << endl;
			cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ~~~  ~~~ \\\\\n        //  ><    ><  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\\n        ////// uu \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\n    ////// uuuuuuuuuu \\\\\\\\\\\\\n    //// \\\\ uuuuuuuu // \\\\\\\\\n     ///  \\\\________//  \\\\\\\n           |        |\n           |        |\n          /|\\      /|\\\n         ^ ^ ^    ^ ^ ^" << endl;
		}
		giveExp();
		levelUp();
	}
	if (heal > 0)
	{
		reset();
	}
	while (heal > 0 && level < 4)
	{
		battleProcess();
	}
}

//**** LEVEL FOUR *****
void levelFour()
{
	if (kills == encounters)
	{
		cout << "I'm glad you've listened to me and not that STISS you plowed through." << endl;
		cout << "Soon, you'll meet GUS. Whatever you do..." << endl;
		cout << "Don't listen to him. Don't listen to anything he says." << endl;
		cout << "Okay?" << endl;
		getline(cin, name, '\n');
		for (int y = 0; y < name.length(); y++)
		{
			name[y] = toupper(name[y]);
		}
		if (name.find("NO", 0) != -1 || name == "N")
		{
			cout << "Why you little bastard!!!\nI'll kill you!!!" << endl;
			heal = 0;
		}
		else if (name.find("YES", 0) != -1 || name == "Y" || name.find("OKAY", 0) != -1)
		{
			cout << "Thanks." << endl;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				swear = name.find(swearAr[j], 0);
				if (swear != -1)
				{
					j = 4;
				}
			}
			if (swear == -1)
			{
				cout << "No idea what you said, but I'll assume you said okay." << endl;
			}
			else
			{
				cout << "Thanks for swearing at me..." << endl;
				heal = 0;
			}
		}
	}
	else if (kills > 0)
	{
		cout << "You need to kill more. But..." << endl;
		cout << "Soon, you'll meet GUS. Whatever you do..." << endl;
		cout << "Don't listen to him. Don't listen to a thing he says." << endl;
		cout << "Okay?" << endl;
		cout << "(You'd better agree before I kill you for being soft.)" << endl;
		getline(cin, name, '\n');
		for (int y = 0; y < name.length(); y++)
		{
			name[y] = toupper(name[y]);
		}
		if (name.find("NO", 0) != -1 || name == "N")
		{
			cout << "Why you bloody bastard!!!\nI'll kill you!!!" << endl;
			heal = 0;
		}
		else if (name.find("YES", 0) != -1 || name == "Y" || name.find("OKAY", 0) != -1)
		{
			cout << "Thanks." << endl;
		}
		else
		{
			for (int j = 0; j < 4; j++)
			{
				swear = name.find(swearAr[j], 0);
				if (swear != -1)
				{
					j = 4;
				}
			}
			if (swear == -1)
			{
				cout << "No idea what you said, but if I were you, I'd hope you said okay." << endl;
			}
			else
			{
				cout << "You think swearing is funny?" << endl;
				heal = 0;
			}
		}
	}
	else
	{
		cout << "I see... we have a pacifist here." << endl;
		cout << "But if you listen to GUS who'll be here soon..." << endl;
		cout << "I swear I'll kill you." << endl;
		if (fear / encounters > 0.75)
		{
			cout << "But I know you won't listen to him.\nYou'd probably torture him like the creatures you've tortured earlier.\nI love it!!!" << endl;
		}
		else
		{
			cout << "I swear!!!" << endl;
		}
	}
	system("PAUSE");
	cout << endl;
	system("CLS");
	if (heal > 0)
	{
		cout << "Now I'm glad we're on the same page..." << endl;
	}
	while (heal > 0 && level < 5)
	{
		cout << "If you see GUS, don't listen to him..." << endl;
		battleProcess();
	}
}

//***** LEVEL UP PROGRAM *****
void levelUp()
{
	while (experience >= 100 * level)
	{
		experience -= 100 * level;
		level++;
		reload = level;
		cout << "LEVEL++ to level " << level << endl << "    Health: +" << levelAr[0] << endl << "    Defense: +" << levelAr[1] << endl << "    Attack: +" << levelAr[2] << endl;
		heal += levelAr[0];
		def += levelAr[1];
		att += levelAr[2];
		cout << "\nNEW STATS:" << endl << "    Health: " << heal << endl << "    Defense: " << def << endl << "    Attack: " << att << endl << endl;
		specAtt = att * 10;
		if (heal > 9000 || def > 9000 || att > 9000)
		{
			cout << "Your stats are... OVER 9000!!!" << endl;
		}
		system("PAUSE");
		cout << endl;
		system("CLS");
	}
}

//***** GIVE EXP *****
void giveExp()
{
	if (level > 1 && level < 4)
	{
		stissKills++;
		stissEncounters++;
		if (attChoice == "SPARE")
		{
			stissKills--;
		}
	}
	else if (level < 6)
	{
		gusKills++;
		gusEncounters++;
		if (attChoice == "SPARE")
		{
			gusKills--;
		}
	}
	experience += expGive;
	if (attChoice != "SPARE")
	{
		if (stissAlive == false)
		{
			expStr = monst + " died and you took ";
			fear += 1;
		}
	}
	cout << expStr << expGive << " exp" << endl;
	if (experience < 100 * level)
	{
		cout << "Exp+ " << expGive << endl << "Total exp: " << experience << endl << "Exp needed to level up: " << 100 * level - experience << endl << endl;
	}
	else
	{
		cout << "You have enough Exp to level up!!!" << endl << endl;
	}
	encounters++;
	kills++;
	system("PAUSE");
	cout << endl;
	system("CLS");
}

//***** PICK MONSTER *****
string pickMonst(string &monster)
{
	int monsterPicker;
	srand(time(NULL));
	monsterPicker = rand() % (level * 3);
	srand(time(NULL));
	opLevel = rand() % (level + 1);
	switch (monsterPicker)
	{
	case 0:
		monster = "SLIME";
		break;
	case 1:
		monster = "SKELE WARRIOR";
		break;
	case 2:
		monster = "RAT";
		break;
	case 3:
		monster = "PLASTIC";
		break;
	case 4:
		monster = "POLLUTION";
		break;
	case 5:
		monster = "DRUGZ";
		break;
	case 6:
		monster = "FISHIES";
		break;
	case 7:
		monster = "LIZARDS";
		break;
	case 8:
		monster = "ANIMAL ABUSE?";
		break;
	}
	return monst;
}

//***** MONSTER STAT DEFINITION *****
void monstDefinition(string monster)
{

	if (monster == "SLIME")
	{
		opHeal = 37;
		opDef = 2;
		opAtt = 3;
		opRes = 7;
		expGive = 25;
	}
	else if (monster == "SKELE WARRIOR")
	{
		opHeal = 39;
		opDef = 3;
		opAtt = 3;
		opRes = 6;
		expGive = 30;
	}
	else if (monster == "RAT")
	{
		opHeal = 34;
		opDef = 2;
		opAtt = 2;
		opRes = 8;
		expGive = 20;
	}
	else if (monster == "PLASTIC")
	{
		opHeal = 58;
		opDef = 4;
		opAtt = 8;
		opRes = 13;
		expGive = 40;
	}
	else if (monster == "POLLUTION")
	{
		opHeal = 63;
		opDef = 5;
		opAtt = 9;
		opRes = 11;
		expGive = 45;
	}
	else if (monster == "DRUGZ")
	{
		opHeal = 52;
		opDef = 3;
		opAtt = 10;
		opRes = 15;
		expGive = 35;
	}
	else if (monster == "FISHIES")
	{
		opHeal = 69;
		opDef = 1;
		opAtt = 20;
		opRes = 23;
		expGive = 55;
	}
	else if (monster == "LIZARDS")
	{
		opHeal = 69;
		opDef = 7;
		opAtt = 15;
		opRes = 27;
		expGive = 50;
	}
	else if (monster == "ANIMAL ABUSE?")
	{
		opHeal = 52;
		opDef = 3;
		opAtt = 18;
		opRes = 19;
		expGive = 60;
	}
	if (kills == encounters && level > 1)
	{
		opHeal = 1;
	}
	opHeal += opLevel;
	opDef += opLevel;
	opAtt += opLevel;
	opRes += opLevel;
	expGive *= (opLevel + 1);
	opResMax = opRes;
	opSpecAtt = opAtt * 10;
	monst = monster;
}

//***** BOSS DEFINITION *****
void bossDefinition(string boss)
{
	if (monst == "STISS")
	{
		opSpec = 0;
		opDefChoice = 0;
		opLevel = 25;
		opHeal = 100;
		opDef = 200;
		opAtt = 5;
		opRes = 25;
		expGive = 125;
		opSpecAtt = att * 10;
	}
}

//***** BOSS OUT *****
void bossOut(string boss)
{
	if (monst == "STISS")
	{
		if (opHeal > 0)
		{
			cout << "STISS ATTACKS YOU..." << endl;
			if (attChoice == "DEFEND" || attChoice == "" || attChoice == "SPARE, but were rejected" || (attChoice == "BIDE" && opSpec >= 10))
			{
				if (opRes > 0)
				{
					cout << "             <><><>\n             <><><>\n           <><><><><>\n         // \\\\\\  /// \\\\\n        //  (O)  (O)  \\\\      ///\n       ||              ||    ////\n       ||     \\**/     ||  /////\n        \\\\     \\/     //  //////\n         |------------| ///////\n         |------------|///////\n          //// uuuuuu /////\n        ////// uuuuuuu ||\n       /////// uuuuuuu ||\n     /////// uuuuuuuuu ||\n    ////// uuuuuuuuuu //\n  ////   \\\\ uuuuuuuu //\n ///      \\\\________//\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
				}
				else
				{
					cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ///  \\\\\\ \\\\\n        //  (O)  (O)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\\n        ////// uu \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\n    ////// uuuuuuuuuu \\\\\\\\\\\\\n    //// \\\\ uuuuuuuu // \\\\\\\\\n     ///  \\\\________//  \\\\\\\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
				}
			}
			else if (attChoice == "ATTACK")
			{
				cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ///  \\\\\\ \\\\\n        //  (O)  (O)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\\n        ////// uu \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\n    ////// uuuuuuuuuu \\\\\\\\\\\\\n    //// \\\\ uuuuuuuu // \\\\\\\\\n     ///  \\\\________//  \\\\\\\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
			}
			else
			{
				if (opSpec < 10)
				{
					cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ___  ___ \\\\\n        //  (-)  (-)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\      \\\\\\\\\n        ////// uu \\\\\\\\\\\\   \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\\\n    ////// uuuuuuuuuu //\n    //// \\\\ uuuuuuuu //\n     ///  \\\\________//\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
				}
			}
			battleInfo();
			monstOut();
		}
		else
		{
			if (what.find("ATT", 0) != -1)
			{
				cout << "STISS WUZ SHOCKED BY YOUR ATTACK" << endl;
				cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ~~~  ~~~ \\\\\n        //  ><    ><  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\\n        ////// uu \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\n    ////// uuuuuuuuuu \\\\\\\\\\\\\n    //// \\\\ uuuuuuuu // \\\\\\\\\n     ///  \\\\________//  \\\\\\\n           |        |\n           |        |\n          /|\\      /|\\\n         ^ ^ ^    ^ ^ ^" << endl;
				battleInfo();
				monstOut();
			}
			else
			{
				cout << "STISS THANKS YOU FOR NOT ATTACKING" << endl;
				cout << "             <><><>\n             <><><>\n           <><><><><>\n         // ^^^  ^^^ \\\\\n        //  (^)  (^)  \\\\\n       ||              ||\n       ||     \\**/     ||\n        \\\\     \\/     //\n         |------------|\n         |------------|\n          //// uu \\\\\\\\      \\\\\\\\\n        ////// uu \\\\\\\\\\\\   \\\\\\\\\\\\\n       /////// uu \\\\\\\\\\\\\\\\\\\\\\\\\\\n     /////// uuuuuu \\\\\\\\\\\\\\\\\n    ////// uuuuuuuuuu //\n    //// \\\\ uuuuuuuu //\n     ///  \\\\________//\n           |        |\n           |        |\n          /|\\      /|\\\n          ^^^      ^^^" << endl;
			}
		}
	}
}

//***** BATTLE PROCESS *****
void battleProcess()
{
	attacks = 0;
	if (boss == false)
	{
		monstDefinition(pickMonst(monst));
		battle();
		if (heal > 0)
		{
			//			healReset(type);
			giveExp();
			levelUp();
			reset();
		}
		else
		{
			cout << "U suk @ this game" << endl;
		}
	}
	else if (monst == "STISS")
	{
		hax = true;
		bossDefinition(monst);
		bossBattle(monst);
	}
}

//***** MONSTER BATTLE INFO *****
void monstOut()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < (25 - monst.length()) / 2; i++)
		{
			cout << "-";
		}
		if (j == 0)
		{
			cout << monst;
		}
	}
	cout << endl;
	cout << "Level " << opLevel << endl;
	cout << "Charge: " << opSpec << "/10" << endl;
	cout << "Reserve: " << opRes << endl;
	cout << "Health: " << opHeal << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
}

//***** MAINSTREAM BATTLE *****
void battle()
{
	while (ded == false)
	{
		if (rep == true)
		{
			battleInfo();
			monstOut();
		}
		attSwitch();
		if (rep == true)
		{
			system("CLS");
		}
	}
	ded = false;
}

//***** BOSS BATTLE *****
void bossBattle(string monster)
{
	while (ded == false)
	{
		if (rep == true)
		{
			bossOut(monst);
		}
		whichSwitch(monst);
		if (rep == true)
		{
			system("CLS");
		}
	}
	if (monster == "STISS" && opHeal == 0 && heal > 0)
	{
		if (kills == encounters)
		{
			fear += attacks;
			cout << phrase << " THAT YOU'RE STILL A MURDERER..." << endl;
			system("PAUSE");
			cout << endl;
			system("CLS");
		}
		else if (kills > 0)
		{
			if (fear / encounters > 0.5)
			{
				fear += attacks;
				cout << phrase << " THAT YOU'RE STILL A KILLER" << endl;
				system("PAUSE");
				cout << endl;
				system("CLS");
			}
			else
			{
				cout << "GOOD JOB...\nI WANT YOU TO KEEP SPARING\n" << endl;
				stissAlive = true;
				fear += attacks;
			}
		}
		else
		{
			if (fear / encounters > 0.5)
			{
				fear += attacks;
				cout << phrase << " THAT YOU SHOULD BURN IN HELL" << endl;
				system("PAUSE");
				cout << endl;
				system("CLS");
			}
			else
			{
				cout << "THANKS FOR NOT KILLING OR ATTACKING ANYONE...\nHAVE SOME EXP" << endl;
				stissAlive = true;
				fear += attacks;
			}
		}
		if (heal > 0 && hax != true)
		{
			giveExp();
			levelUp();
		}
		ded = false;
	}
}


