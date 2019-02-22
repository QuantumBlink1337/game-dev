#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <exception>
#include <memory>
#include "math.h"
#include <sstream>
#include <iomanip>
using namespace std;

// all variables unrelated to game development
bool gamecomplete = false;
bool researchreportstatus = false;
string name = "";
string company = "";
int t = 0;
int d = 0;
float r = 0;
int score = 0;
int money = 70000;
int research = 0;
bool gamestatus = false;
string startgame = "";
string playerchoice = "";
bool researchstatus = false;
string help = "";
string timeto = "";
int sales = rand() % 50 + 10;
int turns = 0;
bool action = false;
bool adventure = false;
bool rpg = false;
bool simulation = false;
bool strategy = false;
bool casual = false;
int phase = 0;
string gamename = "";
string topic = "";
string genre = "";
bool genrecheck = true;
bool isresearchcomplete = false;
string review = "";
string review2 = "";
string review3 = "";
string review4 = "";
bool savegame2 = false;
bool multiplayer2 = false;
bool videoplay2 = false;
bool textani1 = false;
bool savegame1 = false;
bool multiplayer1 = false;
bool videoplay1 = false;
bool enginechoice2 = false;
bool tutorials1 = false;
bool betterexp1 = false;
bool achieve1 = false;
bool character1 = false;
bool tutorials2 = false;
bool betterexp2 = false;
bool achieve2 = false;
bool character2 = false;
bool basicdialogue2 = true;
bool betterdialogue2 = false;
bool dialoguetree2 = false;
bool voiceover2 = false;
bool leveleditor2 = false;
bool eastereggs2 = false;
bool minigames2 = false;
bool dynamic2 = false;
bool openworld2 = false;
bool daynight2 = false;
bool basicsounds2 = true;
bool monosound2 = false;
bool betterai2 = false;
bool basiclore2 = false;
bool richbackstory2 = false;
bool stereosound2 = false;
bool chiptone2 = false;
bool textbase2 = true;
bool twodgraphics12 = true;
bool twodgraphics22 = false;
bool threedgraphics12 = false;
bool twodgraphics32 = false;
bool phase1 = true;
bool phase2 = true;
bool phase3 = true;
bool wincheck = false;
bool textbaseactive = false;
bool twodgraphicsone = false;
bool twodgraphicstwo = false;
bool twodgraphicsthree = false;
bool threedgraphicsone = false;
bool textaniactive = false;
bool savegameactive = false;
bool multiplayeractive = false;
bool videoplaybackactive = false;
bool gametutorialsactive = false;
bool betterexpactive = false;
bool achievementactive = false;
bool characterprogressionactive = false;
bool basicstoryactive = false;
bool basiccutscenesactive = false;
bool advancedstorytellingactive = false;
bool advancedcutscenesactive = false;
bool basicdialogueactive = false;
bool betterdialoguesactive = false;
bool dialoguetreeactive = false;
bool voiceoveractive = false;
bool leveleditoractive = false;
bool eastereggsactive = false;
bool minigamesactive = false;
bool dynamicenvironmentactive = false;
bool betteraiactive = false;
bool basicloreactive = false;
bool openworldactive = false;
bool daynightactive = false;
bool richbackstoryactive = false;
bool basicsoundsactive = false;
bool monosoundactive = false;
bool stereosoundactive = false;
bool chiptoneactive = false;

int phasepoints = 30;
int engine = 0, engine1 = 0;
int gameplay = 0, gameplay1 = 0;
int story = 0, story1 = 0;
int dialogues = 0, dialogues1 = 0;
int leveldesign = 0;
int AI = 0, AI1 = 0;
int worlddesign = 0;
int sound = 0;
bool engine2 = true;
bool gameplay2 = true;
bool story2 = true;
bool dialogues2 = true;
bool leveldesign2 = true;
bool AI2 = true;
bool worlddesign2 = true;
bool graphics2 = true;
string enginemods = "";
int enginemods1 = 0;
// engine bools
string gameplaymods = "";
int gameplaymods1 = 0;
bool gameplaychoice2 = false;
string gameplayno = "";
// story variables
string storyno = "";
bool storychoice2 = false;
bool linestory2 = true;
bool advancedcut2 = false;
bool basiccutscenes2 = false;
bool branchingstory2 = false;
string storymods = "";
int storymods1 = 0;
//
string engineno = "";
// gameplay

// research variables
string textbase = "Text Based ($5,000)"; // begins at 5k, influences tech points by 2%
string twodgraphics1 = "2D Graphics V1 ($15,000)"; // begins at 15k tech point %4
string twodgraphics2 = "???"; // 2d graphics v2, begins at 25k 7% 
string twodgraphics3 = "???"; // 2d graphics v3, begins at 200k costs 80 research
string threedgraphics1 = "???"; // 3d graphics v1, begins at 20k 6%
								// engine tech
string textani = "Text Animations ($4,000)"; // begins at 4k, influences tech points by 0.5%
string savegame = "???"; // save game, begins at 6k, influences tech points by 1%
string multiplayer = "???"; // multiplayer, begins at 8k, influences tech points by 5%
string videoplay = "???"; // video playback, begins at 10k, tech point 7%
						  // gameplay design
string tutorials = "???"; // game tutorials, 10k, design 4%
string betterexp = "???"; // better user experience, 12k design 5%
string achieve = "???"; // achievements, 12k, design 5%
string character = "???"; // character progression, 15k design 7%
						  // story design
string linestory = "Linear Story ($5,000)";  // 5k design 2%
string basiccutscenes = "???"; // basic cutscenes 10k 4%
string branchingstory = "???"; // advanced story 15k 10%
string advancedcut = "???"; // advanced cutscenes 20k 15%
							// dialogue design
string basicdialogue = "Basic Dialogue ($5,000)"; // 2%
string betterdialogue = "???"; // Better Dialogues, 10k, %4
string dialoguetree = "???"; // Dialogue Tree, 20k %8
string voiceover = "???"; // Voice Over, 25k 10%
						  // level design tech
string leveleditor = "???";// Level Editor, 5k 2%
string eastereggs = "???"; // easter eggs, 10k 4%
string minigames = "???"; // minigames, 30k 10%
string dynamic = "???"; // dynamic environment, 50k 15%
						// world design design
string basiclore = "???"; // 5k 2%
string openworld = "???"; // Open world, 10k 4%
string daynight = "???"; // day and night cycle 20k 8%
string richbackstory = "???"; // rich backstory 25k 10%
							  // sound tech
string basicsounds = "Basic Sound ($5,000)"; // 5k 2%
string monosound = "???";// 10k 4%
string stereosound = "???"; // 15k %5
string chiptone = "???"; // chiptone soundtrack 25k 10%
						 // AI tech
string betterai = "???";// 15k 6%

string graphicsA[3] = { "2D Graphics V2 (Cost: $60,000 and 30 Research Points)", "2D Graphics V3 (Cost: $200,000 and 80 Research Points)", "3D Graphics V1 (Cost: $100,000 and 45 Research Points)" };
string engineA[3] = { "Save Game (Cost: $40,000 and 15 Research Points)", "Multiplayer (Cost: $80,000 and 30 Research Points)", "Video Playback (Cost: $150,000 and 50 Research Points)" };
string gameplayA[4] = { "Game Tutorials (Cost: $40,000 and 15 Research Points)", "Better User Experience (Cost: $60,000 and 30 Research Points)", "Achievements (Cost: $100,000 and 50 Research Points)", "Character Progression (Cost: $150,000 and 65 Research Points)" };
string storyA[3] = { "Basic Cutscenes (Cost: $60,000 and 20 Research Points)", "Advanced Storywriting (Cost: $80,000 and 30 Research Points)", "Advanced Cutscenes (Cost $120,000 and 40 Research Points)" };
string dialogueA[3] = { "Better Dialogues (Cost: $50,000 and 20 Research Points)", "Dialogue Tree ($75,000 and 30 Research Points)", "Voice Over (Cost $150,000 and 60 Research Points)" };
string leveldesignA[4] = { "Level Editor (Cost: $50,000 and 20 Research Points", "Easter Eggs (Cost: ($75,000 and 30 Research Points)", "Mini Games (Cost: $100,000 and 45 Research Points", "Dynamic Environment (Cost: $200,000 and 80 Research Points" };
string AIA[1] = { "Better AI (Cost: $75,000 and 45 Research Points" };
string worlddesignA[4] = { "Basic Lore Building (Cost: $40,000 and 15 Research Points)", "Open World (Cost: $75,000 and 30 Research Points)", "Day and Night Cycle (Cost: $90,000 and 50 Research Points", "Rich Backstory (Cost: $50,000 and 30 Research Points)" };
string soundA[3] = { "Mono Soundfont (Cost: $40,000 and 15 Research Points)", "Stereo Soundfont (Cost: $60,000 and 25 Research Points)", "Soundtrack (Cost: $100,000 and 45 Research Points)" };
void modFactor(int designaddin = 0, int techaddin = 0)
{
	// graphics modifiers (bonuses to both)
	if (textbaseactive == true)
	{
		designaddin = designaddin + (d * 0.10);
		techaddin = techaddin + (t * 0.10);
	}
	else if (twodgraphicsone == true) {
		designaddin = designaddin + (d * 0.25);
		techaddin = techaddin + (t * 0.25);
	}
	else if (twodgraphicstwo == true) {
		designaddin = designaddin + (d * 0.40);
		techaddin = techaddin + (t * 0.40);
	}
	else if (twodgraphicsthree == true) {
		designaddin = designaddin + (d * 0.70);
		techaddin = techaddin + (t * 0.70);
	}
	else if (threedgraphicsone == true) {
		designaddin = designaddin + (d * 0.75);
		techaddin = techaddin + (t * 0.75);
	}
	// engine modifiers (all based on tech points)
	if (textaniactive == true)
	{
		techaddin += t * 0.04;
	}
	if (savegameactive == true)
	{
		techaddin += t * 0.08;
	}
	if (multiplayeractive == true)
	{
		techaddin += t * 0.12;
	}
	if (videoplaybackactive == true)
	{
		techaddin += t * 0.20;
	}
	// gameplay modifiers (based on design)
	if (gametutorialsactive == true)
	{
		designaddin += d * 0.04;
	}
	if (betterexpactive == true)
	{
		designaddin += d * 0.12;
	}
	if (achievementactive == true)
	{
		designaddin += d * 0.24;
	}
	if (characterprogressionactive == true)
	{
		designaddin += d * 0.36;
	}
	// story modifiers (design)
	if (basicstoryactive == true)
	{
		designaddin += d * 0.04;
	}
	if (basiccutscenesactive == true)
	{
		designaddin += d * 0.16;
	}
	if (advancedstorytellingactive == true)
	{
		designaddin += d * 0.22;
	}
	if (advancedcutscenesactive == true)
	{
		designaddin += d * 0.40;
	}
	// dialogue modifers (design)
	if (basicdialogueactive == true)
	{
		designaddin += d * 0.04;
	}
	if (betterdialoguesactive == true)
	{
		designaddin += d * 0.14;
	}
	if (dialoguetreeactive == true)
	{
		designaddin += d * 0.20;
	}
	if (voiceoveractive == true)
	{
		designaddin += d * 0.40;
	}
	// level design (tech)
	if (leveleditoractive == true)
	{
		techaddin += t * 0.14;
	}
	if (eastereggsactive == true)
	{
		techaddin += t * 0.20;
	}
	if (minigamesactive == true)
	{
		techaddin += t * 0.25;
	}
	if (dynamicenvironmentactive == true)
	{
		techaddin += t * 0.52;
	}
	// ai (tech)
	if (betteraiactive == true)
	{
		techaddin += t * 0.20;
	}
	// world design (design)
	if (basicloreactive == true)
	{
		designaddin += d * 0.12;
	}
	if (openworldactive == true)
	{
		designaddin += d * 0.20;
	}
	if (daynightactive == true)
	{
		designaddin += d * 0.24;
	}
	if (richbackstoryactive == true)
	{
		designaddin += d * 0.14;
	}
	// sound (tech)

	if (basicsoundsactive == true)
	{
		techaddin += t * 0.04;
	}
	if (monosoundactive == true)
	{
		techaddin += t * 0.10;
	}
	if (stereosoundactive == true)
	{
		techaddin += t * 0.16;
	}
	if (chiptoneactive == true)
	{
		techaddin += t * 0.26;
	}
	cout << techaddin << endl << designaddin << endl;
	t += techaddin + t;
	d += designaddin + d;
	Sleep(5000);
}
void turnCheck() {
	turns = turns + 1;
	
	cout << "You have " << money << " dollars and you are on turn " << turns << endl;
	if (turns % 10 == 0)
	{
		money = money -= 15000;
		cout << "You were charged $15,000 for monthly expenses. Your current balance is " << money << "." << endl;

	}
	if (turns >= 300)
	{
		if (money >= 1500000)
		{
			cout << "Congratulations. You win!" << endl;
			wincheck = true;
		}
		else if (money < 1500000)
		{
			cout << "Unfortunately, you have lost." << endl;
			wincheck = true;

		}
	}
	else if (money <= 0) {
		cout << "Unfortunately, you have gone bankrupt and have lost." << endl;
		wincheck = true;
		phase1 = false;
		phase2 = false;
		phase3 = false;
		researchstatus = false;

	}

}
bool check(string input, string compareToLowerCase)
{
	string tmp = "";
	for (int index = 0; index < input.length(); index++)
	{
		tmp += tolower(input[index]);
	}
	return tmp == compareToLowerCase;
}
void researchProcess() {
	for (int index = 1; index < 5; index++)
	{
		cout << (25 * index) << "% Complete." << endl;

		Sleep(1000);
		turnCheck();
	}
	cout << "Research is Complete!" << endl;

}
void gameDev() {
	phase1 = true;
	phase2 = true;
	phase3 = true;
	bool textbaseactive = false;
	bool twodgraphicsone = false;
	bool twodgraphicstwo = false;
	bool twodgraphicsthree = false;
	bool threedgraphicsone = false;
	textbaseactive = false;
	twodgraphicsone = false;
	twodgraphicstwo = false;
	twodgraphicsthree = false;
	threedgraphicsone = false;
	textaniactive = false;
	savegameactive = false;
	multiplayeractive = false;
	videoplaybackactive = false;
	gametutorialsactive = false;
	betterexpactive = false;
	achievementactive = false;
	characterprogressionactive = false;
	basicstoryactive = false;
	basiccutscenesactive = false;
	advancedstorytellingactive = false;
	advancedcutscenesactive = false;
	basicdialogueactive = false;
	betterdialoguesactive = false;
	dialoguetreeactive = false;
	voiceoveractive = false;
	leveleditoractive = false;
	eastereggsactive = false;
	minigamesactive = false;
	dynamicenvironmentactive = false;
	betteraiactive = false;
	basicloreactive = false;
	openworldactive = false;
	daynightactive = false;
	richbackstoryactive = false;
	basicsoundsactive = false;
	monosoundactive = false;
	stereosoundactive = false;
	chiptoneactive = false;
	engine2 = true;
	gameplay = 0;
	story = 0;
	phasepoints = 30;
	r = 0;
	t = 0;
	int phase2expenses = 0;
	int score = 0;
	srand(time(0));
	cout << "What topic do you want to make your game about? (HINT: You can put in anything you want.)" << endl;
	cin >> topic;
	while (genrecheck == true)
	{
		cout << "What genre of game you want? Action, Adventure, RPG, Simulation, Strategy, or Casual. (HINT: These choices influence what you want to put your points into.)" << endl;
		getline(cin, genre);
		if (name == "cheat") {
			cout << genre << endl;
		}
		if (check(genre, "action"))
		{
			action = true;
			genrecheck = false;
		}
		else if (check(genre, "adventure"))
		{
			adventure = true;
			genrecheck = false;
		}
		else if (check(genre, "rpg"))
		{
			rpg = true;
			genrecheck = false;
		}
		else if (check(genre, "simulation"))
		{
			simulation = true;
			genrecheck = false;
		}
		else if (check(genre, "strategy"))
		{
			strategy = true;
			genrecheck = false;
		}
		else if (check(genre, "casual"))
		{
			casual = true;
			genrecheck = false;
		}
		else
		{
			cout << "Invalid response... please try again." << endl;
			Sleep(1000);
		}
	}
	cout << "What's the name of your game?" << endl;
	getline(cin, gamename);
	if (gamename == "debug")
	{
		cout << "Debug mode enabled. How many turns would you like to set?" << endl;
		cin >> turns;
		cout << "Set to " << turns << " turns. " << endl;
		phase1 = false;
		phase2 = false;
		phase3 = false;
	}
	genrecheck = false;
	bool graphicschoice2 = false;
	string graphicsmods = ";";
	int graphicsmods1 = 0;
	cout << "Select a Graphics type." << textbase << ", " << twodgraphics1 << ", " << twodgraphics2 << ", " << twodgraphics3 << " and " << threedgraphics1 << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
	while (graphicschoice2 == false)
	{ // evaluates whether the boolean graphicschoice2 is false or not. set to true at the end of the loop if the user inputs the correct value for their choice
		if (threedgraphics12 == false && twodgraphics22 == false)
		{
			cout << "Press 1 for " << textbase << ", Press 2 for " << twodgraphics1 << "." << endl;
			cin >> graphicsmods;
			graphicsmods1 = stoi(graphicsmods); // turns graphicmods to a integer instead of string
			if (graphicsmods1 == 1)
			{
				money -= 5000;
				
				graphicschoice2 = true;
				textbaseactive = true;
				cout << "You selected Text Based Graphics." << endl;
			}
			else if (graphicsmods1 == 2)
			{
				money -= 15000;
			
				graphicschoice2 = true;
				twodgraphicsone = true;
				cout << "You selected 2D Graphics V1." << endl;
			}
			else
			{
				cout << "Error." << endl;
			}
		}
		else if (twodgraphics12 == false)
		{
			cout << "Press 1 for " << textbase << ", Press 2 for " << twodgraphics1 << ", Press 3 for " << twodgraphics2 << "." << endl;
			cin >> graphicsmods;
			graphicsmods1 = stoi(graphicsmods);
			if (graphicsmods1 == 1)
			{
				money -= 5000;
			
				graphicschoice2 = true;
				textbaseactive = true;
				cout << "You selected Text Based Graphics." << endl;
			}
			else if (graphicsmods1 == 2)
			{
				money -= 15000;
				
				graphicschoice2 = true;
				twodgraphicsone = true;
				cout << "You selected 2D Graphics V1." << endl;
			}
			else if (graphicsmods1 == 3)
			{
				money -= 25000;
			
				graphicschoice2 = true;
				twodgraphicstwo = true;
				cout << "You selected 2D Graphics V2." << endl;
			}
			else
			{
				cout << "Error." << endl;
			}
		}
		else if (threedgraphics12 == false)
		{
			cout << "Press 1 for " << textbase << ", Press 2 for " << twodgraphics1 << ", Press 3 for " << twodgraphics2 << ", Press 4 for " << twodgraphics3 << "." << endl;
			cin >> graphicsmods;
			graphicsmods1 = stoi(graphicsmods);
			if (graphicsmods1 == 1)
			{
				money -= 5000;
				
				graphicschoice2 = true;
				textbaseactive = true;
				cout << "You selected Text Based Graphics." << endl;
			}
			else if (graphicsmods1 == 2)
			{
				money -= 15000;
				
				graphicschoice2 = true;
				twodgraphicsone = true;
				cout << "You selected 2D Graphics V1." << endl;
			}
			else if (graphicsmods1 == 3)
			{
				money -= 25000;
				
				graphicschoice2 = true;
				twodgraphicstwo = true;
				cout << "You selected 2D Graphics V2." << endl;
			}
			else if (graphicsmods1 == 4)
			{
				money -= 40000;
				
				graphicschoice2 = true;
				cout << "You selected 2D Graphics V3." << endl;
				twodgraphicsthree = true;
			}
			else
			{
				cout << "Error." << endl;
			}
		}
		else 
		{
			cout << "Press 1 for " << textbase << ", Press 2 for " << twodgraphics1 << ", Press 3 for " << twodgraphics2 << ", Press 4 for " << twodgraphics3 << ", Press 5 for " << threedgraphics1 << "." << endl;
			cin >> graphicsmods;
			graphicsmods1 = stoi(graphicsmods);
			if (graphicsmods1 == 1)
			{
				money -= 5000;
				
				graphicschoice2 = true;
				textbaseactive = true;
				cout << "You selected Text Based Graphics." << endl;
			}
			else if (graphicsmods1 == 2)
			{
				money -= 15000;
				
				graphicschoice2 = true;
				twodgraphicsone = true;
				cout << "You selected 2D Graphics V1." << endl;
			}
			else if (graphicsmods1 == 3)
			{
				money -= 25000;
				
				graphicschoice2 = true;
				twodgraphicstwo = true;
				cout << "You selected 2D Graphics V2." << endl;
			}
			else if (graphicsmods1 == 4)
			{
				money -= 40000;
			
				graphicschoice2 = true;
				cout << "You selected 2D Graphics V3." << endl;
				twodgraphicsthree = true;
			}
			else if (graphicsmods1 == 5)
			{
				money -= 20000;
				
				graphicschoice2 = true;
				cout << "You selected 3D Graphics V1." << endl;
				threedgraphicsone = true;
			}
			else
			{
				cout << "Error." << endl;
			}
		}
	}
	Sleep(2000);
	system("cls");
	turnCheck();
	Sleep(1000);
	cout << "Phase 1 preparing to start...." << endl;
	Sleep(2500);
	for (int p = 5; p > phase; p--)
	{
		if (turns <= 50)
		{
			t += (int)(rand() % 2);
			d += (int)(rand() % 2);
			r += (int)(rand() % 2);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;
			Sleep(500);
		}
		else if (turns <= 100)
		{
			t += (int)(rand() % 4 + 1);
			d += (int)(rand() % 4 + 1);
			r += (int)(rand() % 3);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;

			Sleep(500);
		}
		else if (turns <= 150)
		{
			t += (int)(rand() % 8 + 3);
			d += (int)(rand() % 8 + 3);
			r += (int)(rand() % 4);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;

			Sleep(500);
		}
		else if (turns <= 200)
		{
			t += (int)(rand() % 10 + 5);
			d += (int)(rand() % 10 + 5);
			r += (int)(rand() % 5 + 1);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;

			Sleep(500);
		}
		else if (turns <= 250)
		{
			t += (int)(rand() % 13 + 7);
			d += (int)(rand() % 13 + 7);
			r += (int)(rand() % 5 + 2);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;

			Sleep(500);
		}
		else if (turns <= 300)
		{
			t += (int)(rand() % 15 + 8);
			d += (int)(rand() % 15 + 8);
			r += (int)(rand() % 5 + 3);
			cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points." << endl;
			Sleep(500);
		}
	}
	cout << "You have " << t << " Technology points and " << d << " Design points. You have " << r << " research points. (HINT: The points before Phase 1 starts are randomized, but they get higher when advancing through the game!)" << endl;
	Sleep(2500);
	turnCheck();
	int phase1expenses = 0;
	phase1 = true;
	Sleep(500);
	cout << "You have 30 points to spend on three catagories. You have 90 points for the entire game. (HINT: Choose your points wisely! Catagory choice is dependent on your genre choice and do effect review scores!" << endl;
	Sleep(500);
	cout << "Your three catagories are Engine, Gameplay, and Story." << endl;
	while (phase1 == true)
	{
		string enginechoice = "";
		string storychoice = "";
		while (engine2 == true)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on Engine? You have " << phasepoints << " to spend. (Recommended for Simulation and Strategy; Highly Recommended for Action)" << endl;
			cin >> enginechoice;
			engine1 = stoi(enginechoice);
			if (engine1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= engine1;
				engine2 = false;
				cout << "You can select additional features for Engine. (HINT: These can increase your tech score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available Engine Modifiers: " << textani << ", " << savegame << ", " << multiplayer << ", and " << videoplay << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> engineno;
				if (engineno == "no" || engineno == "No")
				{
					enginechoice2 = true;
				}
				while (enginechoice2 == false)
				{
					if (videoplay2 == false && savegame2 == false && multiplayer2 == false)
					{
						cout << "Press 1 for " << textani << "." << endl;
						cin >> enginemods;
						enginemods1 = stoi(enginemods);
						if (enginemods1 == 1)
						{
							textaniactive = true;
							money -= 4000;
							phase1expenses += 4000;
							cout << "You selected Text Animations." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (videoplay2 == false && multiplayer2 == false)
					{
						cout << "Press 1 for " << textani << ", Press 2 for " << savegame << "." << endl;
						cin >> enginemods;
						enginemods1 = stoi(enginemods);
						if (enginemods1 == 1)
						{
							textaniactive = true;
							money -= 4000;
							phase1expenses += 4000;
							cout << "You selected Text Animations." << endl;
						}
						else if (enginemods1 == 2)
						{
							savegameactive = true;
							money -= 10000;
							phase1expenses += 10000;
							cout << "You selected Save Game." << endl;

						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (videoplay2 == false)
					{
						cout << "Press 1 for " << textani << ", Press 2 for " << savegame << ", Press 3 for " << multiplayer << "." << endl;
						cin >> enginemods;
						enginemods1 = stoi(enginemods);
						if (enginemods1 == 1)
						{
							textaniactive = true;
							money -= 4000;
							phase1expenses += 4000;
							cout << "You selected Text Animations." << endl;
						}
						else if (enginemods1 == 2)
						{
							savegameactive = true;
							money -= 10000;
							phase1expenses += 10000;
							cout << "You selected Save Game." << endl;

						}
						else if (enginemods1 == 3)
						{
							multiplayeractive = true;
							money -= 15000;
							phase1expenses += 15000;
							cout << "You selected Multiplayer." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << textani << ", Press 2 for " << savegame << ", Press 3 for " << multiplayer << ", Press 4 for " << videoplay << "." << endl;
						cin >> enginemods;
						enginemods1 = stoi(enginemods);
						if (enginemods1 == 1)
						{
							textaniactive = true;
							money -= 4000;
							phase1expenses += 4000;
							cout << "You selected Text Animations." << endl;
						}
						else if (enginemods1 == 2)
						{
							savegameactive = true;
							money -= 10000;
							phase1expenses += 10000;
							cout << "You selected Save Game." << endl;

						}
						else if (enginemods1 == 3)
						{
							multiplayeractive = true;
							money -= 15000;
							phase1expenses += 15000;
							cout << "You selected Multiplayer." << endl;
						}
						else if (enginemods1 == 4)
						{
							
							money -= 25000;
							phase1expenses += 25000;
							cout << "You selected Video Playback." << endl;
							videoplaybackactive = true;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
					cin >> engineno;
					if (engineno == "no" || engineno == "No")
					{
						enginechoice2 = true;
						
					}
				}
			}
		}

		turnCheck();

		Sleep(1000);
		string gameplaychoice = "";
		while (gameplay == 0)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;
			cout << "How many points would you like to spend on gameplay? You have " << phasepoints << " to spend. (Recommended for Action and RPG; Highly Recommended for Simulation, Casual, and Strategy)" << endl;
			cin >> gameplaychoice;
			gameplay1 = stoi(gameplaychoice);
			if (gameplay1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
				Sleep(1000);
			}
			else
			{
				phasepoints -= gameplay1;
				gameplay2 = false;
				cout << "You can select additional features for Gameplay. (HINT: These can increase your design score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available Gameplay Modifiers: " << tutorials << ", " << betterexp << ", " << achieve << ", and " << character << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> gameplayno;
				if (check(gameplayno, "no"))
				{
					gameplaychoice2 = true;
					gameplay = 1;
				}
				while (gameplaychoice2 == false)
				{
					if (tutorials2 == false && character2 == false && betterexp2 == false && achieve2 == false)
					{
						cout << "No mods available. Try researching some!" << endl;
						Sleep(500);
						gameplaychoice2 = true;
					}
					else if (character2 == false && betterexp2 == false && achieve2 == false)
					{
						cout << "Press 1 for " << tutorials << "." << endl;
						cin >> gameplaymods;
						gameplaymods1 = stoi(gameplaymods);
						if (gameplaymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							gametutorialsactive = true;
							cout << "You selected Game Tutorials." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (character2 == false && achieve2 == false)
					{
						cout << "Press 1 for " << tutorials << ", Press 2 for " << betterexp << "." << endl;
						cin >> gameplaymods;
						gameplaymods1 = stoi(gameplaymods);
						if (gameplaymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							gametutorialsactive = true;
							cout << "You selected Game Tutorials." << endl;
						}
						else if (gameplaymods1 == 2)
						{
							money -= 15000;
							phase1expenses += 15000;
							betterexpactive = true;
							cout << "You selected Better User Experience." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (character2 == false)
					{
						cout << "Press 1 for " << tutorials << ", Press 2 for " << betterexp << ", Press 3 for " << achieve << "." << endl;
						cin >> gameplaymods;
						if (gameplaymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							gametutorialsactive = true;
							cout << "You selected Game Tutorials." << endl;
						}
						else if (gameplaymods1 == 2)
						{
							money -= 15000;
							phase1expenses += 15000;
							betterexpactive = true;
							cout << "You selected Better User Experience." << endl;
						}
						else if (gameplaymods1 == 3)
						{
							money -= 30000;
							phase1expenses += 30000;
							achievementactive = true;
							cout << "You selected Achievements." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << tutorials << ", Press 2 for " << betterexp << ", Press 3 for " << achieve << ", Press 4 for " << character << "." << endl;
						cin >> gameplaymods;
						gameplaymods1 = stoi(gameplaymods);
						if (gameplaymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							gametutorialsactive = true;
							cout << "You selected Game Tutorials." << endl;
						}
						else if (gameplaymods1 == 2)
						{
							money -= 15000;
							phase1expenses += 15000;
							betterexpactive = true;
							cout << "You selected Better User Experience." << endl;
						}
						else if (gameplaymods1 == 3)
						{
							money -= 30000;
							phase1expenses += 30000;
							achievementactive = true;
							cout << "You selected Achievements." << endl;
						}
						else if (gameplaymods1 == 4)
						{
							money -= 45000;
							phase1expenses += 45000;
							characterprogressionactive = true;
							cout << "You selected Character Progression." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
					cin >> gameplayno;
					if (gameplayno == "no" || gameplayno == "No")
					{
						gameplaychoice2 = true;
					}
				}
			}
		}
		turnCheck();

		Sleep(1000);

		while (story == 0)
		{
			cout << gamename << ", a(n)" << genre << "game about " << topic << "." << endl;
			cout << "How many points would you like to spend on story? You have " << phasepoints << " to spend. (Unnecessary for Action and Casual; Highly Recommended for RPG and Adventure)" << endl;
			cin >> storychoice;
			story1 = stoi(storychoice);
			if (story1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= story1;
				story2 = false;
				story = 1;
				cout << "Available Story Modifiers: " << linestory << ", " << basiccutscenes << ", " << branchingstory << ", and " << advancedcut << "." << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> storyno;
				if (storyno == "no" || storyno == "No")
				{
					storychoice2 = true;
				}
				while (storychoice2 == false)
				{
					if (linestory2 == false && advancedcut2 == false && basiccutscenes2 == false && branchingstory2 == false)
					{
						cout << "No mods available. Try researching some!" << endl;
						Sleep(500);
						storychoice2 = true;
					}
					else if (advancedcut2 == false && basiccutscenes2 == false && branchingstory2 == false)
					{
						cout << "Press 1 for " << linestory << "." << endl;
						cin >> storymods;
						storymods1 = stoi(storymods);
						if (storymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							basicstoryactive = true;
							cout << "You selected Basic Story." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (advancedcut2 == false && branchingstory2 == false)
					{
						cout << "Press 1 for " << linestory << ", Press 2 for " << basiccutscenes << "." << endl;
						cin >> storymods;
						storymods1 = stoi(storymods);
						if (storymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							basicstoryactive = true;
							cout << "You selected Basic Story." << endl;
						}
						else if (storymods1 == 2)
						{
							money -= 20000;
							phase1expenses += 20000;
							basiccutscenesactive = true;
							cout << "You selected Basic Cutscenes." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (advancedcut2 == false)
					{
						cout << "Press 1 for " << linestory << ", Press 2 for " << basiccutscenes << ", Press 3 for " << branchingstory << "." << endl;
						cin >> storymods;
						storymods1 = stoi(storymods);
						if (storymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							basicstoryactive = true;
							cout << "You selected Basic Story." << endl;
						}
						else if (storymods1 == 2)
						{
							money -= 20000;
							phase1expenses += 20000;
							basiccutscenesactive = true;
							cout << "You selected Basic Cutscenes." << endl;
						}
						else if (storymods1 == 3)
						{
							money -= 27500;
							phase1expenses += 27500;
							advancedstorytellingactive = true;
							cout << "You selected Advanced Storytelling." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << linestory << ", Press 2 for " << basiccutscenes << ", Press 3 for " << branchingstory << ", Press 4 for " << advancedcut << "." << endl;
						cin >> storymods;
						storymods1 = stoi(storymods);
						if (storymods1 == 1)
						{
							money -= 5000;
							phase1expenses += 5000;
							basicstoryactive = true;
							cout << "You selected Basic Story." << endl;
						}
						else if (storymods1 == 2)
						{
							money -= 20000;
							phase1expenses += 20000;
							basiccutscenesactive = true;
							cout << "You selected Basic Cutscenes." << endl;
						}
						else if (storymods1 == 3)
						{
							money -= 27500;
							phase1expenses += 27500;
							advancedstorytellingactive = true;
							cout << "You selected Advanced Storytelling." << endl;
						}
						else if (storymods1 == 4)
						{
							money -= 40000;
							phase1expenses += 40000;
							advancedcutscenesactive = true;
							cout << "You selected Advanced Cutscenes." << endl;
 						}
						else
						{
							cout << "Error." << endl;
						}
					}
					cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
					cin >> storyno;
					if (storyno == "no" || storyno == "No")
					{
						storychoice2 = true;
					}
				}
			}
		}
		phase1 = false;
	}

	cout << "Phase 1 Expenses: " << phase1expenses << "." << endl;
	Sleep(1000);
	turnCheck();

	phasepoints = 30;
	cout << "Finishing Phase 1 development and preparing Phase 2...." << endl;
	Sleep(1500);
	for (int p = 5; p > phase; p--)
	{
		if (turns <= 50)
		{
			if (engine1 == 20)
			{
				t += (int)(rand() % 3 + 1);
				d += (int)(rand() % 2);
			}
			else if (engine >= 10)
			{
				t += (int)(rand() % 2 + 1);
				d += (int)(rand() % 3);
			}
			else if (engine1 >= 5)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			if (gameplay1 == 20)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3 + 1);
			}
			else if (gameplay1 >= 10)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2 + 1);
			}
			else if (gameplay1 >= 5)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			if (story1 == 20)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3 + 1);
			}
			else if (story1 >= 10)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2 + 1);
			}
			else if (story1 >= 5)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			r += (int)(rand() % 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 100)
		{
			if (engine1 == 20)
			{
				t += (int)(rand() % 6 + 2);
				d += (int)(rand() % 4);
			}
			else if (engine >= 10)
			{
				t += (int)(rand() % 4 + 2);
				d += (int)(rand() % 6);
			}
			else if (engine1 >= 5)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
			if (gameplay1 == 20)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6 + 2);
			}
			else if (gameplay1 >= 10)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 4 + 2);
			}
			else if (gameplay1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 4);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
			if (story1 == 20)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6 + 2);
			}
			else if (story1 >= 10)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 4 + 2);
			}
			else if (story1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 2);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
			r += (int)(rand() % 3);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns >= 150)
		{
			if (engine1 == 20)
			{
				t += (int)(rand() % 9 + 3);
				d += (int)(rand() % 6);
			}
			else if (engine >= 10)
			{
				t += (int)(rand() % 6 + 3);
				d += (int)(rand() % 9);
			}
			else if (engine1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (gameplay1 == 20)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9 + 3);
			}
			else if (gameplay1 >= 10)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6 + 3);
			}
			else if (gameplay1 >= 5)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (story1 == 20)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9 + 3);
			}
			else if (story1 >= 10)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6 + 3);
			}
			else if (story1 >= 5)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			r += (int)(rand() % 4 + 1);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 200)
		{
			if (engine1 == 20)
			{
				t += (int)(rand() % 24 + 8);
				d += (int)(rand() % 16);
			}

			else if (engine >= 10)
			{
				t += (int)(rand() % 16 + 8);
				d += (int)(rand() % 24);
			}
			else if (engine1 >= 5)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			if (gameplay1 == 20)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24 + 8);
			}
			else if (gameplay1 >= 10)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 16 + 8);
			}
			else if (gameplay1 >= 5)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 16);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			if (story1 == 20)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24 + 8);
			}
			else if (story1 >= 10)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 16 + 8);
			}
			else if (story1 >= 5)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 8);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			r += (int)(rand() % 5 + 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 250)
		{
			if (engine1 == 20)
			{
				t += (int)(rand() % 30 + 10);
				d += (int)(rand() % 20);
			}
			else if (engine >= 10)
			{
				t += (int)(rand() % 20 + 10);
				d += (int)(rand() % 30);
			}
			else if (engine1 >= 5)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			if (gameplay1 == 20)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30 + 10);
			}
			else if (gameplay1 >= 10)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 20 + 10);
			}
			else if (gameplay1 >= 5)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 20);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			if (story1 == 20)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30 + 10);
			}
			else if (story1 >= 10)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 20 + 10);
			}
			else if (story1 >= 5)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 10);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			r += (int)(rand() % 6 + 4);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
	}
	bool dialogue2 = true;
	int dialogue1 = 0;
	string dialogueno = "";
	bool dialoguechoice2 = false;
	string dialoguemods = "";
	int dialoguemods1 = 0;

	int  leveldesign1 = 0;
	string  leveldesignno = "";
	bool  leveldesignchoice2 = false;
	string  leveldesignmods = "";
	int  leveldesignmods1 = 0;


	string  AIno = "";
	bool  AIchoice2 = false;
	string  AImods = "";
	int  AImods1 = 0;
	turnCheck();
	phase1 = false;
	cout << "Your three categories are Dialogue, Level Design, and AI." << endl;
	Sleep(1000);
	while (phase2 == true)
	{
		string dialoguechoice = "";
		string leveldesignchoice = "";
		string AIchoice = "";
		while (dialogue2 == true)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on Dialogue? You have " << phasepoints << " to spend. (Horrible for Action; Terrible for Simulation, Casual, and Strategy; Highly Recommended for Adventure and RPG)" << endl;
			cin >> dialoguechoice;
			dialogue1 = stoi(dialoguechoice);
			if (dialogue1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= dialogue1;
				dialogue2 = false;
				dialoguechoice2 = false;
				cout << "You can select additional features for Dialogue. (HINT: These can increase your design score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available Dialogue Modifiers: " << basicdialogue << ", " << betterdialogue << ", " << dialoguetree << ", and " << voiceover << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> dialogueno;
				if (dialogueno == "no" || dialogueno == "No")
				{
					dialoguechoice2 = true;
				}
				while (dialoguechoice2 == false)
				{
					if (voiceover2 == false && betterdialogue2 == false && dialoguetree2 == false)
					{
						cout << "Press 1 for " << basicdialogue << "." << endl;
						cin >> dialoguemods;
						dialoguemods1 = stoi(dialoguemods);
						if (dialoguemods1 == 1)
						{
							money -= 5000;
							phase2expenses += 5000;
							basicdialogueactive = true;
							cout << "You selected Basic Dialogues." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (voiceover2 == false && dialoguetree2 == false)
					{
						cout << "Press 1 for " << basicdialogue << ", Press 2 for " << betterdialogue << "." << endl;
						cin >> dialoguemods;
						dialoguemods1 = stoi(dialoguemods);
						if (dialoguemods1 == 1)
						{
							money -= 5000;
							phase2expenses += 5000;
							basicdialogueactive = true;
							cout << "You selected Basic Dialogues." << endl;
						}
						else if (dialoguemods1 == 2)
						{
							money -= 17500;
							phase2expenses += 17500;
							betterdialoguesactive = true;
							cout << "You selected Better Dialogues." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (voiceover2 == false)
					{
						cout << "Press 1 for " << basicdialogue << ", Press 2 for " << betterdialogue << ", Press 3 for " << dialoguetree << "." << endl;
						cin >> dialoguemods;
						dialoguemods1 = stoi(dialoguemods);
						if (dialoguemods1 == 1)
						{
							money -= 5000;
							phase2expenses += 5000;
							basicdialogueactive = true;
							cout << "You selected Basic Dialogues." << endl;
						}
						else if (dialoguemods1 == 2)
						{
							money -= 17500;
							phase2expenses += 17500;
							betterdialoguesactive = true;
							cout << "You selected Better Dialogues." << endl;
						}
						else if (dialoguemods1 == 3)
						{
							dialoguetreeactive = true;
							money -= 17500;
							phase2expenses += 17500;
							cout << "You selected Dialogue Tree." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << basicdialogue << ", Press 2 for " << betterdialogue << ", Press 3 for " << dialoguetree << ", Press 4 for " << voiceover << "." << endl;
						cin >> dialoguemods;
						dialoguemods1 = stoi(dialoguemods);
						if (dialoguemods1 == 1)
						{
							money -= 5000;
							phase2expenses += 5000;
							basicdialogueactive = true;
							cout << "You selected Basic Dialogues." << endl;
						}
						else if (dialoguemods1 == 2)
						{
							money -= 17500;
							phase2expenses += 17500;
							betterdialoguesactive = true;
							cout << "You selected Better Dialogues." << endl;
						}
						else if (dialoguemods1 == 3)
						{
							dialoguetreeactive = true;
							money -= 17500;
							phase2expenses += 17500;
							cout << "You selected Dialogue Tree." << endl;
						}
						else if (dialoguemods1 == 4)
						{
							voiceoveractive = true;
							money -= 50000;
							phase2expenses += 50000;
							cout << "You selected Voice Acting." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					
					cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
					cin >> dialogueno;
					if (dialogueno == "no" || dialogueno == "No")
					{
						dialoguechoice2 = true;
					}

				}
			}
		}
		turnCheck();

		Sleep(1000);
		while (leveldesign == 0)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on Level Design? You have " << phasepoints << " to spend. (Recommended for Action and RPG; Highly Recommended for Simulation, Casual, and Strategy)" << endl;
			cin >> leveldesignchoice;
			leveldesign1 = stoi(leveldesignchoice);
			if (leveldesign1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
				Sleep(1000);
			}
			else
			{
				phasepoints -= leveldesign1;
				leveldesign2 = false;
				cout << "You can select additional features for Level Design. (HINT: These can increase your tech score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available Level Design Modifiers: " << leveleditor << ", " << eastereggs << ", " << minigames << ", and " << dynamic << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> leveldesignno;
				if (leveldesignno == "no" || leveldesignno == "No")
				{
					leveldesignchoice2 = true;
					leveldesign = 1;
				}
				while (leveldesignchoice2 == false)
				{
					if (leveleditor2 == false && dynamic2 == false && eastereggs2 == false && minigames2 == false)
					{
						cout << "No mods available. Try researching some!" << endl;
						Sleep(500);
						leveldesignchoice2 = true;
					}
					else if (dynamic2 == false && eastereggs2 == false && minigames2 == false)
					{
						cout << "Press 1 for " << leveleditor << "." << endl;
						cin >> leveldesignmods;
						leveldesignmods1 = stoi(leveldesignmods);
						if (leveldesignmods1 == 1)
						{
							money -= 17500;
							phase2expenses += 17500;
							leveleditoractive = true;
							cout << "You selected Level Editor." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (dynamic2 == false && minigames2 == false)
					{
						cout << "Press 1 for " << leveleditor << ", Press 2 for " << eastereggs << "." << endl;
						cin >> leveldesignmods;
						leveldesignmods1 = stoi(leveldesignmods);
						if (leveldesignmods1 == 1)
						{
							money -= 17500;
							phase2expenses += 17500;
							leveleditoractive = true;
							cout << "You selected Level Editor." << endl;
						}
						else if (leveldesignmods1 == 2)
						{
							
							money -= 25000;
							phase2expenses += 25000;
							eastereggsactive = true;
							cout << "You selected Easter Eggs." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (dynamic2 == false)
					{
						cout << "Press 1 for " << leveleditor << ", Press 2 for " << eastereggs << ", Press 3 for " << minigames << "." << endl;
						cin >> leveldesignmods;
						leveldesignmods1 = stoi(leveldesignmods);
						if (leveldesignmods1 == 1)
						{
							money -= 17500;
							phase2expenses += 17500;
							leveleditoractive = true;
							cout << "You selected Level Editor." << endl;
						}
						else if (leveldesignmods1 == 2)
						{

							money -= 25000;
							phase2expenses += 25000;
							eastereggsactive = true;
							cout << "You selected Easter Eggs." << endl;
						}
						else if (leveldesignmods1 == 3)
						{
							minigamesactive = true;
							money -= 32000;
							phase2expenses += 32000;
							cout << "You selected Mini Games." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << leveleditor << ", Press 2 for " << eastereggs << ", Press 3 for " << minigames << ", Press 4 for " << dynamic << "." << endl;
						cin >> leveldesignmods;
						leveldesignmods1 = stoi(leveldesignmods);
						if (leveldesignmods1 == 1)
						{
							money -= 17500;
							phase2expenses += 17500;
							leveleditoractive = true;
							cout << "You selected Level Editor." << endl;
						}
						else if (leveldesignmods1 == 2)
						{

							money -= 25000;
							phase2expenses += 25000;
							eastereggsactive = true;
							cout << "You selected Easter Eggs." << endl;
						}
						else if (leveldesignmods1 == 3)
						{
							minigamesactive = true;
							money -= 32000;
							phase2expenses += 32000;
							cout << "You selected Mini Games." << endl;
						}
						else if (leveldesignmods1 == 4)
						{
							dynamicenvironmentactive = true;
							money -= 65000;
							phase2expenses += 65000;
							cout << "You selected Dynamic Environment." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
						cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
						cin >> leveldesignno;
						if (leveldesignno == "no" || leveldesignno == "No")
						{
							leveldesignchoice2 = true;
						}
					}
				}
			}
		}
		turnCheck();

		while (AI == 0)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on AI? You have " << phasepoints << " to spend. " << endl << "(Highly Recommended for Action and Simulation; Recommended for Strategy; Negligible for RPG; Terrible for Adventure and Casual)" << endl;
			cin >> AIchoice;
			AI1 = stoi(AIchoice);
			if (AI1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= AI1;
				AI2 = false;
				AI = 1;
				cout << "Available AI Modifiers: " << betterai << "." << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> AIno;
				if (AIno == "no" || AIno == "No")
				{
					AIchoice2 = true;
				}
				while (AIchoice2 == false)
				{
					if (betterai2 == false)
					{
						cout << "No mods available. Try researching some!" << endl;
						Sleep(500);
						AIchoice2 = true;
					}
					else
					{
						cout << "Press 1 for " << betterai << "." << endl;
						cin >> AImods;
						AImods1 = stoi(AImods);
						if (AImods1 == 1)
						{
							betteraiactive = true;
							money -= 25000;
							phase2expenses += 25000;
							cout << "You selected Better AI." << endl;
							AIchoice = true;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					
				}
			}
		}
		phase2 = false;
	}
	cout << "Phase 2 Expenses: " << phase2expenses << "." << endl;
	Sleep(1000);
	turnCheck();

	phasepoints = 30;
	cout << "Finishing Phase 2 development and preparing Phase 3...." << endl;
	Sleep(1500);
	for (int p = 5; p > phase; p--)
	{
		if (turns <= 50)
		{
			if (AI1 == 20)
			{
				t += (int)(rand() % 3 + 1);
				d += (int)(rand() % 2);
			}
			else if (AI >= 10)
			{
				t += (int)(rand() % 2 + 1);
				d += (int)(rand() % 3);
			}
			else if (AI1 >= 5)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			if (leveldesign1 == 20)
			{
				t += (int)(rand() % 3 + 1);
				d += (int)(rand() % 2);
			}
			else if (leveldesign1 >= 10)
			{
				t += (int)(rand() % 2 + 1);
				d += (int)(rand() % 3);
			}
			else if (leveldesign1 >= 5)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3);
			}
			if (dialogue1 == 20)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3 + 1);
			}
			else if (dialogue1 >= 10)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2 + 1);
			}
			else if (dialogue1 >= 5)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			r += (int)(rand() % 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 100)
		{
			if (AI1 == 20)
			{
				t += (int)(rand() % 6 + 2);
				d += (int)(rand() % 4);
			}
			else if (AI >= 10)
			{
				t += (int)(rand() % 4 + 2);
				d += (int)(rand() % 6);
			}
			else if (AI1 >= 5)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
			if (leveldesign1 == 20)
			{
				t += (int)(rand() % 6 + 2);
				d += (int)(rand() % 4);
			}
			else if (leveldesign >= 10)
			{
				t += (int)(rand() % 4 + 2);
				d += (int)(rand() % 6);
			}
			else if (leveldesign1 >= 5)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
		
		if (dialogue1 == 20)
		{
			t += (int)(rand() % 4);
			d += (int)(rand() % 6 + 2);
		}
		else if (dialogue1 >= 10)
		{
			t += (int)(rand() % 6);
			d += (int)(rand() % 4 + 2);
		}
		else if (dialogue1 >= 5)
		{
			t += (int)(rand() % 6);
			d += (int)(rand() % 2);
		}
		else
		{
			t += (int)(rand() % 4);
			d += (int)(rand() % 4);
		}
		r += (int)(rand() % 3);
		cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
		Sleep(500);
		}
		else if (turns >= 150)
		{
			if (AI1 == 20)
			{
				t += (int)(rand() % 9 + 3);
				d += (int)(rand() % 6);
			}
			else if (AI >= 10)
			{
				t += (int)(rand() % 6 + 3);
				d += (int)(rand() % 9);
			}
			else if (AI1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (leveldesign1 == 20)
			{
				t += (int)(rand() % 9 + 3);
				d += (int)(rand() % 6);
			}
			else if (leveldesign1 >= 10)
			{
				t += (int)(rand() % 6 + 3);
				d += (int)(rand() % 9);
			}
			else if (leveldesign1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (dialogue1 == 20)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9 + 3);
			}
			else if (dialogue1 >= 10)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6 + 3);
			}
			else if (dialogue1 >= 5)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			r += (int)(rand() % 4 + 1);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 200)
		{
			if (AI1 == 20)
			{
				t += (int)(rand() % 24 + 8);
				d += (int)(rand() % 16);
			}

			else if (AI >= 10)
			{
				t += (int)(rand() % 16 + 8);
				d += (int)(rand() % 24);
			}
			else if (AI1 >= 5)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			if (leveldesign1 == 20)
			{
				t += (int)(rand() % 24 + 8);
				d += (int)(rand() % 16);
			}

			else if (leveldesign1 >= 10)
			{
				t += (int)(rand() % 16 + 8);
				d += (int)(rand() % 24);
			}
			else if (leveldesign1 >= 5)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24);
			}
			if (dialogue1 == 20)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24 + 8);
			}
			else if (dialogue1 >= 10)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 16 + 8);
			}
			else if (dialogue1 >= 5)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 8);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			r += (int)(rand() % 5 + 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 250)
		{
			if (AI1 == 20)
			{
				t += (int)(rand() % 30 + 10);
				d += (int)(rand() % 20);
			}
			else if (AI >= 10)
			{
				t += (int)(rand() % 20 + 10);
				d += (int)(rand() % 30);
			}
			else if (AI1 >= 5)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			if (leveldesign1 == 20)
			{
				t += (int)(rand() % 30 + 10);
				d += (int)(rand() % 20);
			}
			else if (leveldesign >= 10)
			{
				t += (int)(rand() % 20 + 10);
				d += (int)(rand() % 30);
			}
			else if (leveldesign1 >= 5)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30);
			}
			if (dialogue1 == 20)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30 + 10);
			}
			else if (dialogue1 >= 10)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 20 + 10);
			}
			else if (dialogue1 >= 5)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 10);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			r += (int)(rand() % 6 + 4);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
	}
	bool sound2 = true;
	int sound1 = 0;
	string soundno = "";
	bool soundchoice2 = false;
	string soundmods = "";
	int soundmods1 = 0;

	int  worlddesign1 = 0;
	string  worlddesignno = "";
	bool  worlddesignchoice2 = false;
	string  worlddesignmods = "";
	int  worlddesignmods1 = 0;
	int  graphics1 = 0;
	string  graphicsno = "";


	phase2 = false;
	int phase3expenses = 0;

	cout << "Your three categories are Sound, Level Design, and Graphics." << endl;
	while (phase3 == true)
	{
		string soundchoice = "";
		string worlddesignchoice = "";
		string graphicschoice = "";
		while (sound2 == true)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on Sound? You have " << phasepoints << " to spend. " << endl << "(Recommended for Action, Simulation, Strategy, and Casual; Neglibible for Adventure and RPG)" << endl;
			cin >> soundchoice;
			sound1 = stoi(soundchoice);
			if (sound1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= sound1;
				sound2 = false;
				cout << "You can select additional features for Sound. (HINT: These can increase your tech score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available Sound Modifiers: " << basicsounds << ", " << monosound << ", " << stereosound << ", and " << chiptone << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> soundno;
				if (soundno == "no" || soundno == "No")
				{
					soundchoice2 = true;
				}
				while (soundchoice2 == false)
				{
					if (chiptone2 == false && monosound2 == false && stereosound2 == false)
					{
						cout << "Press 1 for " << basicsounds << "." << endl;
						cin >> soundmods;
						soundmods1 = stoi(soundmods);
						if (soundmods1 == 1)
						{
							basicsoundsactive = true;
							money -= 5000;
							phase3expenses += 5000;
							cout << "You selected Basic Sounds." <<  endl;

						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else if (chiptone2 == false && stereosound2 == false)
					{
						cout << "Press 1 for " << basicsounds << ", Press 2 for " << monosound << "." << endl;
						cin >> soundmods;
						soundmods1 = stoi(soundmods);
						if (soundmods1 == 1)
						{
							basicsoundsactive = true;
							money -= 5000;
							phase3expenses += 5000;
							cout << "You selected Basic Sounds." <<  endl;

						}
						else if (soundmods1 == 2)
						{
							monosoundactive = true;
							money -= 12500;
							phase3expenses += 12500;
							cout << "You selected Mono Sounds." << endl;
						}


						else
						{
							cout << "Error." << endl;
						}
					}
					else if (chiptone2 == false)
					{
						cout << "Press 1 for " << basicsounds << ", Press 2 for " << monosound << ", Press 3 for " << stereosound << "." << endl;
						cin >> soundmods;
						soundmods1 = stoi(soundmods);
						if (soundmods1 == 1)
						{
							basicsoundsactive = true;
							money -= 5000;
							phase3expenses += 5000;
							cout << "You selected Basic Sounds." << endl;

						}
						else if (soundmods1 == 2)
						{
							monosoundactive = true;
							money -= 12500;
							phase3expenses += 12500;
							cout << "You selected Mono Sounds." << endl;
						}
						else if (soundmods1 == 3)
						{
							stereosoundactive = true;
							money -= 20000;
							phase3expenses += 20000;
							cout << "You selected Stereo Sound." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << basicsounds << ", Press 2 for " << monosound << ", Press 3 for " << stereosound << ", Press 4 for " << chiptone << "." << endl;
						cin >> soundmods;
						soundmods1 = stoi(soundmods);
						if (soundmods1 == 1)
						{
							basicsoundsactive = true;
							money -= 5000;
							phase3expenses += 5000;
							cout << "You selected Basic Sounds." << endl;

						}
						else if (soundmods1 == 2)
						{
							monosoundactive = true;
							money -= 12500;
							phase3expenses += 12500;
							cout << "You selected Mono Sounds." << endl;
						}
						else if (soundmods1 == 3)
						{
							stereosoundactive = true;
							money -= 20000;
							phase3expenses += 20000;
							cout << "You selected Stereo Sound." << endl;
						}
						else if (soundmods1 == 4)
						{
							chiptoneactive = true;
							money -= 33000;
							phase3expenses += 33000;
							cout << "You selected Soundtrack." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
					}
					cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
					cin >> soundno;
					if (soundno == "no" || soundno == "No")
					{
						soundchoice2 = true;
					}

				}
			}
		}

		turnCheck();

		Sleep(1000);
		while (worlddesign == 0)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on World Design? You have " << phasepoints << " to spend." << endl << "(Highly Recommended for Adventure, RPG, and Strategy; Negligible for Action, Simulation, and Casual)" << endl;
			cin >> worlddesignchoice;
			worlddesign1 = stoi(worlddesignchoice);
			if (worlddesign1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
				Sleep(1000);
			}
			else
			{
				phasepoints -= worlddesign1;
				worlddesign2 = false;
				cout << "You can select additional features for World Design. (HINT: These can increase your design score, but be sure not to overspend!" << endl;
				Sleep(1000);
				cout << "Available World Design Modifiers: " << basiclore << ", " << openworld << ", " << daynight << ", and " << richbackstory << " (HINT: You can unlock the missing modifiers by Researching them.)" << endl;
				Sleep(500);
				cout << "Do you want to add mods?" << endl;
				cin >> worlddesignno;
				if (worlddesignno == "no" || worlddesignno == "No")
				{
					worlddesignchoice2 = true;
					worlddesign = 1;
				}
				while (worlddesignchoice2 == false)
				{
					if (basiclore2 == false && richbackstory2 == false && openworld2 == false && daynight2 == false)
					{
						cout << "No mods available. Try researching some!" << endl;
						Sleep(500);
						worlddesignchoice2 = true;
					}
					else if (richbackstory2 == false && openworld2 == false && daynight2 == false)
					{
						cout << "Press 1 for " << basiclore << "." << endl;
						cin >> worlddesignmods;
						worlddesignmods1 = stoi(worlddesignmods);
						if (worlddesignmods1 == 1)
						{
							basicloreactive = true;
							cout << "You selected Basic Lore Building." << endl;
							money -= 15000;
							phase3expenses += 15000;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else if (richbackstory2 == false && daynight2 == false)
					{
						cout << "Press 1 for " << basiclore << ", Press 2 for " << openworld << "." << endl;
						cin >> worlddesignmods;
						worlddesignmods1 = stoi(worlddesignmods);
						if (worlddesignmods1 == 1)
						{
							basicloreactive = true;
							cout << "You selected Basic Lore Building." << endl;
							money -= 15000;
							phase3expenses += 15000;
						}
						else if (worlddesignmods1 == 2)
						{
							openworldactive = true;
							money -= 25000;
							phase3expenses += 25000;
							cout << "You selected Open World." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else if (richbackstory2 == false)
					{
						cout << "Press 1 for " << basiclore << ", Press 2 for " << openworld << ", Press 3 for " << daynight << "." << endl;
						cin >> worlddesignmods;
						worlddesignmods1 = stoi(worlddesignmods);
						if (worlddesignmods1 == 1)
						{
							basicloreactive = true;
							cout << "You selected Basic Lore Building." << endl;
							money -= 15000;
							phase3expenses += 15000;
						}
						else if (worlddesignmods1 == 2)
						{
							openworldactive = true;
							money -= 25000;
							phase3expenses += 25000;
							cout << "You selected Open World." << endl;
						}
						else if (worlddesignmods1 == 3)
						{
							daynightactive = true;
							money -= 30000;
							phase3expenses += 30000;
							cout << "You selected Day and Night Cycle." << endl;
						}

						else
						{
							cout << "Error." << endl;
						}
					}
					else
					{
						cout << "Press 1 for " << basiclore << ", Press 2 for " << openworld << ", Press 3 for " << daynight << ", Press 4 for " << richbackstory << "." << endl;
						cin >> worlddesignmods;
						worlddesignmods1 = stoi(worlddesignmods);
						if (worlddesignmods1 == 1)
						{
							basicloreactive = true;
							cout << "You selected Basic Lore Building." << endl;
							money -= 15000;
							phase3expenses += 15000;
						}
						else if (worlddesignmods1 == 2)
						{
							openworldactive = true;
							money -= 25000;
							phase3expenses += 25000;
							cout << "You selected Open World." << endl;
						}
						else if (worlddesignmods1 == 3)
						{
							daynightactive = true;
							money -= 30000;
							phase3expenses += 30000;
							cout << "You selected Day and Night Cycle." << endl;
						}
						else if (worlddesignmods1 == 4)
						{
							richbackstoryactive = true;
							money = -17500;
							phase3expenses += 17500;
							cout << "You selected Rich Backstory." << endl;
						}
						else
						{
							cout << "Error." << endl;
						}
						cout << "Continue adding mods? (If you only have one mod choice say no)" << endl;
						cin >> worlddesignno;
						if (worlddesignno == "no" || worlddesignno == "No")
						{
							worlddesignchoice2 = true;
						}
					}
				}
			}
		}
		turnCheck();

		graphics1 = 0;
		while (graphics1 == 0)
		{
			cout << gamename << ", a(n)" << genre << " game about " << topic << "." << endl;

			cout << "How many points would you like to spend on Graphics? You have " << phasepoints << " to spend. " << endl << "(Highly Recommended for Action, Simulation, and Casual; Recommended for Adventure and RPG)" << endl;
			cin >> graphicschoice;
			graphics1 = stoi(graphicschoice);
			if (graphics1 > phasepoints)
			{
				cout << "You exceeded your points usage. Try again." << endl;
			}
			else
			{
				phasepoints -= graphics1;
				graphics2 = false;
				graphics1 = 1;
			}
		}
		cout << "Phase 3 Expenses: " << phase3expenses << "." << endl;
		Sleep(1000);
		turnCheck();

		Sleep(500);
		cout << "Finishing Phase 3 development and preparing sales...." << endl;
		Sleep(1500);
		phase3 = false;
	}
	for (int p = 5; p > phase; p--)
	{
		if (turns >= 50)
		{
			if (graphics1 == 20)
			{
				t += (int)(rand() % 3 + 1);
				d += (int)(rand() % 2);
			}
			else if (graphics1 >= 10)
			{
				t += (int)(rand() % 2 + 1);
				d += (int)(rand() % 3);
			}
			else if (graphics1 >= 5)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			if (sound1 == 20)
			{
				t += (int)(rand() % 3 + 1);
				d += (int)(rand() % 2);
			}
			else if (sound1 >= 10)
			{
				t += (int)(rand() % 2 + 1);
				d += (int)(rand() % 3);
			}
			else if (sound1 >= 5)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3);
			}
			if (worlddesign1 == 20)
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 3 + 1);
			}
			else if (worlddesign1 >= 10)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2 + 1);
			}
			else if (worlddesign1 >= 5)
			{
				t += (int)(rand() % 3);
				d += (int)(rand() % 2);
			}
			else
			{
				t += (int)(rand() % 2);
				d += (int)(rand() % 2);
			}
			r += (int)(rand() % 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 100)
		{
			if (graphics1 == 20)
			{
				t += (int)(rand() % 6 + 2);
				d += (int)(rand() % 4);
			}
			else if (graphics1 >= 10)
			{
				t += (int)(rand() % 4 + 2);
				d += (int)(rand() % 6);
			}
			else if (graphics1 >= 5)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
			if (sound1 == 20)
			{
				t += (int)(rand() % 6 + 2);
				d += (int)(rand() % 4);
			}
			else if (sound >= 10)
			{
				t += (int)(rand() % 4 + 2);
				d += (int)(rand() % 6);
			}
			else if (sound1 >= 5)
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 4);
				d += (int)(rand() % 4);
			}
		
		if (worlddesign1 == 20)
		{
			t += (int)(rand() % 4);
			d += (int)(rand() % 6 + 2);
		}
		else if (worlddesign1 >= 10)
		{
			t += (int)(rand() % 6);
			d += (int)(rand() % 4 + 2);
		}
		else if (worlddesign1 >= 5)
		{
			t += (int)(rand() % 6);
			d += (int)(rand() % 2);
		}
		else
		{
			t += (int)(rand() % 4);
			d += (int)(rand() % 4);
		}
		r += (int)(rand() % 3);
		cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
		Sleep(500);
		}
		else if (turns >= 150)
		{
			if (graphics1 == 20)
			{
				t += (int)(rand() % 9 + 3);
				d += (int)(rand() % 6);
			}
			else if (graphics1 >= 10)
			{
				t += (int)(rand() % 6 + 3);
				d += (int)(rand() % 9);
			}
			else if (graphics1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (sound1 == 20)
			{
				t += (int)(rand() % 9 + 3);
				d += (int)(rand() % 6);
			}
			else if (sound1 >= 10)
			{
				t += (int)(rand() % 6 + 3);
				d += (int)(rand() % 9);
			}
			else if (sound1 >= 5)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			if (worlddesign1 == 20)
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 9 + 3);
			}
			else if (worlddesign1 >= 10)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6 + 3);
			}
			else if (worlddesign1 >= 5)
			{
				t += (int)(rand() % 9);
				d += (int)(rand() % 6);
			}
			else
			{
				t += (int)(rand() % 6);
				d += (int)(rand() % 6);
			}
			r += (int)(rand() % 4 + 1);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 200)
		{
			if (graphics1 == 20)
			{
				t += (int)(rand() % 24 + 8);
				d += (int)(rand() % 16);
			}

			else if (graphics1 >= 10)
			{
				t += (int)(rand() % 16 + 8);
				d += (int)(rand() % 24);
			}
			else if (graphics1 >= 5)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			if (sound1 == 20)
			{
				t += (int)(rand() % 24 + 8);
				d += (int)(rand() % 16);
			}

			else if (sound1 >= 10)
			{
				t += (int)(rand() % 16 + 8);
				d += (int)(rand() % 24);
			}
			else if (sound1 >= 5)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24);
			}
			if (worlddesign1 == 20)
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 24 + 8);
			}
			else if (worlddesign1 >= 10)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 16 + 8);
			}
			else if (worlddesign1 >= 5)
			{
				t += (int)(rand() % 24);
				d += (int)(rand() % 8);
			}
			else
			{
				t += (int)(rand() % 16);
				d += (int)(rand() % 16);
			}
			r += (int)(rand() % 5 + 2);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
		else if (turns <= 250)
		{
			if (graphics1 == 20)
			{
				t += (int)(rand() % 30 + 10);
				d += (int)(rand() % 20);
			}
			else if (graphics1 >= 10)
			{
				t += (int)(rand() % 20 + 10);
				d += (int)(rand() % 30);
			}
			else if (graphics1 >= 5)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			if (sound1 == 20)
			{
				t += (int)(rand() % 30 + 10);
				d += (int)(rand() % 20);
			}
			else if (sound >= 10)
			{
				t += (int)(rand() % 20 + 10);
				d += (int)(rand() % 30);
			}
			else if (sound1 >= 5)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30);
			}
			if (worlddesign1 == 20)
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 30 + 10);
			}
			else if (worlddesign1 >= 10)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 20 + 10);
			}
			else if (worlddesign1 >= 5)
			{
				t += (int)(rand() % 30);
				d += (int)(rand() % 10);
			}
			else
			{
				t += (int)(rand() % 20);
				d += (int)(rand() % 20);
			}
			r += (int)(rand() % 6 + 4);
			cout << "You have " << t << " Technology points and " << d << " Design points, and " << r << " Research points. " << endl;
			Sleep(500);
		}
	}

	modFactor();
	Sleep(1000);
	int design = d;
	int tech = t; 
	cout << design << endl << tech << endl;
	cout << "Final Design Points (after mod factoring) " << design << ". Final Technology Points (after mod factoring) " << tech << "." << endl;
	if (action == true)
	{ // phase 1 checking
		if (engine1 == 20) {
			score = score + 3;
		}
		else if (engine1 >= 10)
		{
			score = score + 2;
		}
		else if (engine1 >= 5)
		{
			score = score + 1;
		}
		else if (engine1 < 4)
		{
			score = score + 0;
		}

		if (gameplay1 == 10) {
			score = score + 3;
		}
		else if (gameplay1 <= 20)
		{
			score = score + 2;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 1;
		}
		else if (gameplay1 < 4)
		{
			score = score + 0;
		}

		if (story2 <= 2)
		{
			score = score + 3;
		}
		else if (story1 <= 5) {
			score = score + 2;
		}
		else if (story1 >= 6)
		{
			score = score + 1;
		}
		else if (story1 >= 10) {
			score = score + 0;
		}

		if (AI1 == 20) {
			score = score + 3;
		}
		else if (AI1 >= 10)
		{
			score = score + 2;
		}
		else if (AI1 >= 5)
		{
			score = score + 1;
		}
		else if (AI1 < 4)
		{
			score = score + 0;
		}

		if (leveldesign1 == 10) {
			score = score + 3;
		}
		else if (leveldesign1 <= 20)
		{
			score = score + 2;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 1;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 0;
		}

		if (dialogue1 <= 1)
		{
			score = score + 3;
		}
		else if (dialogue1 <= 4) {
			score = score + 2;
		}
		else if (dialogue1 >= 6)
		{
			score = score + 1;
		}
		else if (dialogue1 >= 10) {
			score = score + 0;
		}

		if (graphics1 == 20) {
			score = score + 3;
		}
		else if (graphics1 >= 10)
		{
			score = score + 2;
		}
		else if (graphics1 >= 5)
		{
			score = score + 1;
		}
		else if (graphics1 < 4)
		{
			score = score + 0;
		}

		if (sound1 == 10) {
			score = score + 3;
		}
		else if (sound1 <= 20)
		{
			score = score + 2;
		}
		else if (sound1 >= 5)
		{
			score = score + 1;
		}
		else if (sound1 < 4)
		{
			score = score + 0;
		}

		if (worlddesign1 <= 2)
		{
			score = score + 3;
		}
		else if (worlddesign1 <= 5) {
			score = score + 2;
		}
		else if (worlddesign1 >= 6)
		{
			score = score + 1;
		}
		else if (worlddesign1 >= 10) {
			score = score + 0;
		}



		if (turns < 75) {
			if (t > 120 && d > 70)
			{
				score = score + 2;
			}
			else if (t > 110 && d > 80)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 240 && d > 140)
			{
				score = score + 2;
			}
			else if (t > 220 && d > 160)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
	}
	else if (adventure == true)
	{
		if (engine1 == 20) {
			score = score + 0;
		}

		else if (engine1 >= 10)
		{
			score = score + 1;
		}
		else if (engine1 >= 5)
		{
			score = score + 2;
		}
		else if (engine1 < 4)
		{
			score = score + 3;
		}
		if (gameplay1 == 20) {
			score = score + 0;
		}

		else if (gameplay1 <= 1)
		{
			score = score + 1;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 2;
		}
		else if (gameplay1 < 4)
		{
			score = score + 3;
		}
		if (story2 == 20)
		{
			score = score + 3;
		}
		else if (story1 >= 10) {
			score = score + 2;
		}
		else if (story1 >= 5)
		{
			score = score + 1;
		}
		else if (story1  < 5) {
			score = score + 0;
		}
		if (AI1 == 20) {
			score = score + 0;
		}

		else if (AI1 >= 10)
		{
			score = score + 1;
		}
		else if (AI1 >= 5)
		{
			score = score + 2;
		}
		else if (AI1 < 4)
		{
			score = score + 3;
		}
		if (leveldesign1 == 20) {
			score = score + 0;
		}

		else if (leveldesign1 < 20)
		{
			score = score + 1;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 2;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 3;
		}
		if (dialogue1 == 20)
		{
			score = score + 3;
		}
		else if (dialogue1 >= 15) {
			score = score + 2;
		}
		else if (dialogue1 >= 5)
		{
			score = score + 1;
		}
		else if (dialogue1 <= 4) {
			score = score + 0;
		}
		if (graphics1 == 15) {
			score = score + 3;
		}

		else if (graphics1 >= 20)
		{
			score = score + 2;
		}
		else if (graphics1 >= 5)
		{
			score = score + 1;
		}
		else if (graphics1 < 4)
		{
			score = score + 0;
		}
		if (sound1 == 20) {
			score = score + 0;
		}

		else if (sound1 < 20)
		{
			score = score + 1;
		}
		else if (sound1 >= 5)
		{
			score = score + 2;
		}
		else if (sound1 < 4)
		{
			score = score + 3;
		}
		if (worlddesign1 <= 20)
		{
			score = score + 3;
		}
		else if (worlddesign1 >= 15) {
			score = score + 2;
		}
		else if (worlddesign1 >= 5)
		{
			score = score + 1;
		}
		else if (worlddesign1 <= 4) {
			score = score + 0;
		}
		if (turns < 75) {
			if (t > 70 && d > 120)
			{
				score = score + 2;
			}
			else if (t > 80 && d > 110)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 140 && d > 240)
			{
				score = score + 2;
			}
			else if (t > 160 && d > 220)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
	}

	else if (rpg == true)
	{
		if (engine1 == 20) {
			score = score + 0;
		}

		else if (engine1 >= 10)
		{
			score = score + 1;
		}
		else if (engine1 >= 5)
		{
			score = score + 2;
		}
		else if (engine1 < 4)
		{
			score = score + 3;
		}
		if (gameplay1 == 10) {
			score = score + 3;
		}

		else if (gameplay1 <= 20)
		{
			score = score + 2;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 1;
		}
		else if (gameplay1 < 4)
		{
			score = score + 0;
		}
		if (story2 == 20)
		{
			score = score + 3;
		}
		else if (story1 >= 10) {
			score = score + 2;
		}
		else if (story1 >= 5)
		{
			score = score + 1;
		}
		else if (story1  < 5) {
			score = score + 0;
		}
		if (AI1 == 20) {
			score = score + 0;
		}

		else if (AI1 >= 10)
		{
			score = score + 1;
		}
		else if (AI1 >= 5)
		{
			score = score + 2;
		}
		else if (AI1 < 4)
		{
			score = score + 3;
		}
		if (leveldesign1 == 10) {
			score = score + 3;
		}

		else if (leveldesign1 <= 20)
		{
			score = score + 2;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 1;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 0;
		}
		if (dialogue1 == 20)
		{
			score = score + 3;
		}
		else if (dialogue1 >= 15) {
			score = score + 2;
		}
		else if (dialogue1 >= 5)
		{
			score = score + 1;
		}
		else if (dialogue1 <= 4) {
			score = score + 0;
		}
		if (graphics1 == 15) {
			score = score + 3;
		}

		else if (graphics1 >= 20)
		{
			score = score + 2;
		}
		else if (graphics1 >= 5)
		{
			score = score + 1;
		}
		else if (graphics1 < 4)
		{
			score = score + 0;
		}
		if (sound1 == 20) {
			score = score + 0;
		}

		else if (sound1 < 20)
		{
			score = score + 1;
		}
		else if (sound1 >= 5)
		{
			score = score + 2;
		}
		else if (sound1 < 4)
		{
			score = score + 3;
		}
		if (worlddesign1 <= 20)
		{
			score = score + 3;
		}
		else if (worlddesign1 >= 15) {
			score = score + 2;
		}
		else if (worlddesign1 >= 5)
		{
			score = score + 1;
		}
		else if (worlddesign1 <= 4) {
			score = score + 0;
		}
		if (turns < 75) {
			if (t > 70 && d > 120)
			{
				score = score + 2;
			}
			else if (t > 80 && d > 110)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 140 && d > 240)
			{
				score = score + 2;
			}
			else if (t > 160 && d > 220)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
	}

	else if (simulation == true)
	{
		if (engine1 == 10) {
			score = score + 3;
		}

		else if (engine1 <= 20)
		{
			score = score + 2;
		}
		else if (engine1 >= 5)
		{
			score = score + 1;
		}
		else if (engine1 < 4)
		{
			score = score + 0;
		}

		if (gameplay1 <= 20)
		{
			score = score + 3;
		}
		else if (gameplay1 >= 15) {
			score = score + 2;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 1;
		}
		else if (gameplay1 <= 4) {
			score = score + 0;
		}
		if (story2 <= 2)
		{
			score = score + 3;
		}
		else if (story1 <= 5) {
			score = score + 2;
		}
		else if (story1 >= 6)
		{
			score = score + 1;
		}
		else if (story1 >= 10) {
			score = score + 0;
		}
		if (AI1 == 20) {
			score = score + 3;
		}

		else if (AI1 >= 10)
		{
			score = score + 2;
		}
		else if (AI1 >= 5)
		{
			score = score + 1;
		}
		else if (AI1 < 4)
		{
			score = score + 0;
		}
		if (leveldesign1 == 10) {
			score = score + 3;
		}

		else if (leveldesign1 <= 20)
		{
			score = score + 2;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 1;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 0;
		}
		if (dialogue1 <= 1)
		{
			score = score + 3;
		}
		else if (dialogue1 <= 4) {
			score = score + 2;
		}
		else if (dialogue1 >= 6)
		{
			score = score + 1;
		}
		else if (dialogue1 >= 10) {
			score = score + 0;
		}
		if (graphics1 == 20) {
			score = score + 3;
		}

		else if (graphics1 >= 10)
		{
			score = score + 2;
		}
		else if (graphics1 >= 5)
		{
			score = score + 1;
		}
		else if (graphics1 < 4)
		{
			score = score + 0;
		}
		if (sound1 == 10) {
			score = score + 3;
		}

		else if (sound1 <= 20)
		{
			score = score + 2;
		}
		else if (sound1 >= 5)
		{
			score = score + 1;
		}
		else if (sound1 < 4)
		{
			score = score + 0;
		}
		if (worlddesign1 <= 2)
		{
			score = score + 3;
		}
		else if (worlddesign1 <= 5) {
			score = score + 2;
		}
		else if (worlddesign1 >= 6)
		{
			score = score + 1;
		}
		else if (worlddesign1 >= 10) {
			score = score + 0;
		}
		if (turns < 75) {
			if (t > 120 && d > 70)
			{
				score = score + 2;
			}
			else if (t > 110 && d > 80)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 240 && d > 140)
			{
				score = score + 2;
			}
			else if (t > 220 && d > 160)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
	}
	else if (strategy == true)
	{
		if (engine1 == 10) {
			score = score + 3;
		}
		else if (engine1 <= 20)
		{
			score = score + 2;
		}
		else if (engine1 >= 5)
		{
			score = score + 1;
		}
		else if (engine1 < 4)
		{
			score = score + 0;
		}

		if (gameplay1 <= 20)
		{
			score = score + 3;
		}
		else if (gameplay1 >= 15) {
			score = score + 2;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 1;
		}
		else if (gameplay1 <= 4) {
			score = score + 0;
		}
		if (story2 <= 2)
		{
			score = score + 3;
		}
		else if (story1 <= 5) {
			score = score + 2;
		}
		else if (story1 >= 6)
		{
			score = score + 1;
		}
		else if (story1 >= 10) {
			score = score + 0;
		}
		if (leveldesign1 == 20) {
			score = score + 3;
		}

		else if (leveldesign1 >= 10)
		{
			score = score + 2;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 1;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 0;
		}
		if (AI1 == 10) {
			score = score + 3;
		}

		else if (AI1 <= 20)
		{
			score = score + 2;
		}
		else if (AI1 >= 5)
		{
			score = score + 1;
		}
		else if (AI1 < 4)
		{
			score = score + 0;
		}
		if (dialogue1 <= 1)
		{
			score = score + 3;
		}
		else if (dialogue1 <= 4) {
			score = score + 2;
		}
		else if (dialogue1 >= 6)
		{
			score = score + 1;
		}
		else if (dialogue1 >= 10) {
			score = score + 0;
		}
		if (worlddesign1 <= 20)
		{
			score = score + 3;
		}
		else if (worlddesign1 >= 15) {
			score = score + 2;
		}
		else if (worlddesign1 >= 5)
		{
			score = score + 1;
		}
		else if (worlddesign1 <= 4) {
			score = score + 0;
		}
		if (graphics1 == 20) {
			score = score + 0;
		}

		else if (graphics1 >= 10)
		{
			score = score + 1;
		}
		else if (graphics1 >= 5)
		{
			score = score + 2;
		}
		else if (graphics1 < 4)
		{
			score = score + 3;
		}
		if (sound1 == 10) {
			score = score + 3;
		}

		else if (sound1 <= 20)
		{
			score = score + 2;
		}
		else if (sound1 >= 5)
		{
			score = score + 1;
		}
		else if (sound1 < 4)
		{
			score = score + 0;
		}
		if (turns < 75) {
			if (t > 70 && d > 120)
			{
				score = score + 2;
			}
			else if (t > 80 && d > 110)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 140 && d > 240)
			{
				score = score + 2;
			}
			else if (t > 160 && d > 220)
			{
				score = score + 1;
			}
			else {
				score = score + 0;
			}
		}
	}
	else if (casual == true)
	{
		if (engine1 == 20) {
			score = score + 0;
		}

		else if (engine1 >= 10)
		{
			score = score + 1;
		}
		else if (engine1 >= 5)
		{
			score = score + 2;
		}
		else if (engine1 < 4)
		{
			score = score + 3;
		}
		if (gameplay1 == 20)
		{
			score = score + 3;
		}
		else if (gameplay1 >= 15) {
			score = score + 2;
		}
		else if (gameplay1 >= 5)
		{
			score = score + 1;
		}
		else if (gameplay1 <= 4) {
			score = score + 0;
		}
		if (story2 == 20)
		{
			score = score + 3;
		}
		else if (story1 >= 10) {
			score = score + 2;
		}
		else if (story1 >= 5)
		{
			score = score + 1;
		}
		else if (story1  < 5) {
			score = score + 0;
		}
		if (dialogue1 <= 3)
		{
			score = score + 3;
		}
		else if (dialogue1 <= 4) {
			score = score + 2;
		}
		else if (dialogue1 >= 6)
		{
			score = score + 1;
		}
		else if (dialogue1 >= 10) {
			score = score + 0;
		}
		if (leveldesign1 == 20) {
			score = score + 3;
		}

		else if (leveldesign1 >= 10)
		{
			score = score + 2;
		}
		else if (leveldesign1 >= 5)
		{
			score = score + 1;
		}
		else if (leveldesign1 < 4)
		{
			score = score + 0;
		}
		if (AI1 == 20) {
			score = score + 0;
		}

		else if (AI1 >= 10)
		{
			score = score + 1;
		}
		else if (AI1 >= 5)
		{
			score = score + 2;
		}
		else if (AI1 < 4)
		{
			score = score + 3;
		}
		if (graphics1 == 20) {
			score = score + 3;
		}

		else if (graphics1 >= 10)
		{
			score = score + 2;
		}
		else if (graphics1 >= 5)
		{
			score = score + 1;
		}
		else if (graphics1 < 4)
		{
			score = score + 0;
		}
		if (sound1 == 10) {
			score = score + 3;
		}

		else if (sound1 <= 20)
		{
			score = score + 2;
		}
		else if (sound1 >= 5)
		{
			score = score + 1;
		}
		else if (sound1 < 4)
		{
			score = score + 0;
		}
		if (worlddesign1 <= 2)
		{
			score = score + 3;
		}
		else if (worlddesign1 <= 5) {
			score = score + 2;
		}
		else if (worlddesign1 >= 6)
		{
			score = score + 1;
		}
		else if (worlddesign1 >= 10) {
			score = score + 0;
		}

		if (turns < 75) {
			if (t > 120 && d > 70)
			{
				score = score + 2;
			}
			else if (t > 110 && d > 80)
			{
				score = score + 1;
			}
			else
			{
				score = score + 0;
			}
		}
		else if (turns < 150) {
			if (t > 240 && d > 140)
			{
				score = score + 2;
			}
			else if (t > 220 && d > 160)
			{
				score = score + 1;
			}
			else
			{
				score = score + 0;
			}
		}
	}
	if (name == "debug") {
		cout << "Debug mode has been detected. What score would you like?" << endl;
		cin >> score;
	}
	int salesmoney = sales * 40;
	cout << "Your game " << name << " (" << topic << "/" << genre << ") will now be reviewed." << endl << "(HINT: Reviews are extremely important.They affect sales of the game, and by definition, your profit!)" << endl;
	Sleep(1000);

	Sleep(500);
	if (score == 29 && (d >= 180 || t >= 180))
	{
		review = "10";
		cout << "Ten. A perfect game. - All Games" << endl;
		review2 = "10";
		Sleep(2000);
		cout << "I have to give this game a 10. It's a masterpiece. - ReviewCorp" << endl;
		review3 = "10";
		Sleep(2000);
		cout << " 10. Why are you reading this? Go out and buy it! - GameCritics" << endl;
		review4 = "10";
		Sleep(2000);
		cout << "Best game on the market right now. A perfect game, and a perfect score to fit it. Ten out of ten. - UsersChoice" << endl;

	}
	else if (score >= 22)
	{
		review = to_string(rand() % 3 + 7);
		cout << review << ". Interesting game. It's very good. Would recommend. - All Games" << endl;
		review2 = to_string(rand() % 3 + 7);
		Sleep(2000);
		cout << review2 << ". I'm excited to see what other games " << company << "has to offer. - ReviewCorp" << endl;
		Sleep(2000);
		review3 = to_string(rand() % 3 + 7);
		cout << review3 << ". Very good game for the money. Looking forward to the sequel. - GameCritics" << endl;
		Sleep(2000);

		review4 = to_string(rand() % 3 + 7);
		cout << review4 << ". " << name << "'s company " << company << " has a bright future. Looking forward to more. - UsersChoice" << endl;

	}
	else if (score >= 16)
	{
		review = to_string(rand() % 3 + 4);
		cout << review << ". Not good. Not bad. - All Games" << endl;
		review2 = to_string(rand() % 3 + 4);
		Sleep(2000);
		cout << review2 << ". It's okay I guess. Needs refinement. - ReviewCorp" << endl;
		review3 = to_string(rand() % 3 + 4);
		Sleep(2000);
		cout << review3 << ". It's getting there. Still needs more work. - GameCritics" << endl;
		review4 = to_string(rand() % 3 + 4);
		Sleep(2000);
		cout << review4 << ". Needs some improvement but otherwise a good start. - UsersChoice" << endl;

	}
	else if (score <= 10)
	{
		review = to_string(rand() % 3 + 1);
		cout << review << ". Bad! - All Games" << endl;
		review2 = to_string(rand() % 3 + 1);
		Sleep(2000);
		cout << review2 << ". Fails in every regard. - ReviewCorp" << endl;
		review3 = to_string(rand() % 3 + 1);
		Sleep(2000);
		cout << review3 << ". Terrible game. - GameCritics" << endl;
		Sleep(2000);

		review4 = to_string(rand() % 3 + 1);
		cout << review4 << ". " << company << " needs to step up their game if they want to survive. - UsersChoice" << endl;

	}
	else
	{
		review = to_string(rand() % 3 + 1);
		cout << review << ". This is an actual game? That people made? - All Games" << endl;
		review2 = to_string(rand() % 3 + 1);
		Sleep(2000);
		cout << review2 << ". Fails in every regard. I have no clue what this even is! - ReviewCorp" << endl;
		review3 = to_string(rand() % 3 + 1);
		Sleep(2000);
		cout << review3 << ". Terrible game. " << company << " needs to figure out how to make a(n) " << genre << " game. - GameCritics" << endl;
		Sleep(2000);

		review4 = to_string(rand() % 3 + 1);
		cout << review4 << ". " << company << " needs to step up their game if they want to survive. - UsersChoice" << endl;
	}
	turnCheck();

	cout << "Your game " << gamename << " is about to hit the market!" << endl;
	Sleep(2000);
	// written by Robb
	double profitPool = (8.2) * exp(0.42 * (score - 3)) + 40000;
	double totalProfitForPrinting = profitPool;

	for (int p = 7; p > phase; p--)
	{
		double distribute = .65 * profitPool; //slowly give the money to the player. fastest at the start, slows down
		profitPool -= distribute;
		money += distribute;
		cout << "You made " << distribute << " dollars." << endl;
		turnCheck();

		Sleep(1000);

	}
	//final pass gets the rest of the money

	double distribute = profitPool; //slowly give the money to the player. fastest at the start, slows down
									//profitPool -= distribute; //doesn't need to happen, profitPool never used again
	money += distribute;


	cout << "You generated " << totalProfitForPrinting << " in total sales. You earned " << totalProfitForPrinting << " from " << gamename << ". Your current balance is " << money << "." << endl;
	d = 0;
	t = 0;
	genrecheck = true;
	gamecomplete = true;
	Sleep(5000);
	system("cls");
	turnCheck();


}
void researchFunc(int researchchoice = 0, int percentage = 0, bool researchstatus = false, int research = 0, bool validresponse = false, int choiceIndex = 0, int researchIndex = 0, int moneyIndex = 0) {
	cout << "What would you like to research?" << endl;
	Sleep(500);
	cout << "Press 1 for Graphics, Press 2 for Engine, Press 3 for Gameplay, Press 4 for Story, " << endl << " Press 5 for Dialogues, Press 6 for Level Design, Press 7 for AI, " << endl << " Press 8 for Sound, and 9 for World Design." << endl;
	cin >> researchchoice;
	cout << "Hint: You need to have the prerequisite research in order to research the next modifier. For example, you can't research 3D Graphics without having 2D Graphics done." << endl;
	Sleep(1000);
	if (researchchoice == 100) {
		cout << graphicsA[0] << endl;
		cout << graphicsA[1] << endl;
		cout << engineA[0] << endl;
		cout << engineA[1] << endl;
		cout << engineA[2] << endl;

	}
	if (researchchoice == 1)

	{
		cout << "You have " << money << " dollars and you have " << r << " points. " << endl;

		cout << "Press 0 for " << graphicsA[0] << " or Press 1 for " << graphicsA[1] << "or Press 2 for " << graphicsA[2] << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (graphicsA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 30 || money < 60000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 80 || money < 200000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 45 || money < 100000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0)
			{
				
				r = r - 30;
				money = money - 60000;
				researchProcess();
				twodgraphics2 = "2D Graphics V2 ($25,000)";
				twodgraphics22 = true;
				graphicsA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && graphicsA[choiceIndex - 1] == "---")
			{
				

				r = r - 80;
				money = money - 200000;
				researchProcess();
				twodgraphics3 = "2D Graphics V3 ($40,000)";
				graphicsA[choiceIndex] = "---";
				twodgraphics32 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && graphicsA[choiceIndex - 1] == "---")
			{


				r = r - 45;
				money = money - 100000;
				researchProcess();
				threedgraphics1 = "3D Graphics V1 ($20,000)";
				graphicsA[choiceIndex] = "---";
				threedgraphics12 = true;
				researchstatus = true;
			}
			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;
			}
		}
	
	}
	else if (researchchoice == 2) {
		cout << "Press 0 for " << engineA[0] << ", Press 1 for " << engineA[1] << ", or Press 2 for " << engineA[2] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (engineA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 15 || money < 40000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 80000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 50 || money < 150000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0)
			{
			
				r = r - 15;
				money = money - 40000;
				researchProcess();
				savegame = "Save Game ($10,000)";
				savegame2 = true;
				engineA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex  == 1 && engineA[choiceIndex - 1] == "---")
			{
				
				r = r - 30;
				money = money - 80000;
				researchProcess();

				multiplayer = "Multiplayer ($15,000)";
				engineA[choiceIndex] = "---";
				multiplayer2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && engineA[choiceIndex - 1] == "---")
			{

				r = r - 50;
				money = money - 150000;
				researchProcess();

				videoplay = "Video Playback ($25,000)";
				engineA[choiceIndex] = "---";
				videoplay2 = true;
				researchstatus = true;
			}
			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 3) {
		cout << "Press 0 for " << gameplayA[0] << ", Press 1 for " << gameplayA[1] << ", or Press 2 for " << gameplayA[2] << ", or Press 3 for " << gameplayA[3] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (gameplayA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 15 || money < 40000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 80000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 50 || money < 100000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 3 && (r < 65 || money < 150000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0)
			{

				r = r - 15;
				money = money - 40000;
				researchProcess();
				tutorials = "Game Tutorials ($5,000)";
				tutorials2 = true;
				gameplayA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && gameplayA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 80000;
				researchProcess();
				betterexp = "Better User Experience ($15,000)";
				gameplayA[choiceIndex] = "---";
				betterexp2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && gameplayA[choiceIndex - 1] == "---")
			{
				r = r - 50;
				money = money - 100000;
				researchProcess();
				achieve = "Achievements ($30,000)";
				gameplayA[choiceIndex] = "---";
				achieve2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 3 && gameplayA[choiceIndex - 1] == "---")
			{
				r = r - 65;
				money = money - 150000;
				researchProcess();
				character = "Character Progression ($45,000)";
				gameplayA[choiceIndex] = "---";
				character2 = true;
				researchstatus = true;
			}
			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 4) {
		cout << "Press 0 for " << storyA[0] << ", Press 1 for " << storyA[1] << ", or Press 2 for " << storyA[2] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (storyA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 20 || money < 60000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 80000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 40 || money < 120000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}

			else if (choiceIndex == 0)
			{

				r = r - 20;
				money = money - 60000;
				researchProcess();
				basiccutscenes = "Basic Cutscenes ($20,000)";
				basiccutscenes2 = true;
				storyA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && storyA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 80000;
				researchProcess();
				branchingstory = "Advanced Storytelling ($27,500)";
				storyA[choiceIndex] = "---";
				branchingstory2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && storyA[choiceIndex - 1] == "---")
			{
				r = r - 40;
				money = money - 120000;
				researchProcess();
				advancedcut = "Advanced Cutscenes ($40,000)";
				storyA[choiceIndex] = "---";
				advancedcut2 = true;
				researchstatus = true;
			}

			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 5) {
		cout << "Press 0 for " << dialogueA[0] << ", Press 1 for " << dialogueA[1] << ", or Press 2 for " << dialogueA[2] << "." << endl;
			cin >> choiceIndex;
		while (researchstatus == false) {
			if (dialogueA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 20 || money < 50000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 75000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 60 || money < 150000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}


			else if (choiceIndex == 0)
			{

				r = r - 20;
				money = money - 50000;
				researchProcess();
				betterdialogue = "Better Dialogues ($17,500)";
				betterdialogue2 = true;
				dialogueA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && dialogueA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 75000;
				researchProcess();
				dialoguetree = "Dialogue Tree ($25,000)";
				dialogueA[choiceIndex] = "---";
				dialoguetree2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && dialogueA[choiceIndex - 1] == "---")
			{
				r = r - 60;
				money = money - 150000;
				researchProcess();
				voiceover = "Voice Over ($50,000)";
				dialogueA[choiceIndex] = "---";
				voiceover2 = true;
				researchstatus = true;
			}


			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 6) {
		cout << "Press 0 for " << leveldesignA[0] << ", Press 1 for " << leveldesignA[1] << ", or Press 2 for " << leveldesignA[2] << ", or Press 3 for " << leveldesignA[3] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (leveldesignA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 20 || money < 50000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 75000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 45 || money < 100000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 3 && (r < 80 || money < 200000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0)
			{

				r = r - 20;
				money = money - 50000;
				researchProcess();
				leveleditor = "Level Editor ($17,500)";
				leveleditor2 = true;
				leveldesignA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && leveldesignA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 75000;
				researchProcess();
				eastereggs = "Easter Eggs ($25,000)";
				leveldesignA[choiceIndex] = "---";
				eastereggs2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && leveldesignA[choiceIndex - 1] == "---")
			{
				r = r - 45;
				money = money - 100000;
				researchProcess();
				minigames = "Mini Games ($32,500)";
				leveldesignA[choiceIndex] = "---";
				minigames2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 3 && leveldesignA[choiceIndex - 1] == "---")
			{
				r = r - 80;
				money = money - 200000;
				researchProcess();
				dynamic = "Dynamic Environment ($65,000)";
				leveldesignA[choiceIndex] = "---";
				dynamic2 = true;
				researchstatus = true;
			}
			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 7) {
		cout << "Press 0 for " << AIA[0] << ", Press 1 for " << AIA[1] << ", or Press 2 for " << AIA[2] << ", or Press 3 for " << AIA[3] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (AIA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 45 || money < 75000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}

			else if (choiceIndex == 0)
			{

				r = r - 45;
				money = money - 75000;
				researchProcess();
				betterai = "Advanced AI ($25,000)";
				betterai2 = true;
				AIA[choiceIndex] = "---";
				researchstatus = true;
			}

			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 8) {
		cout << "Press 0 for " << worlddesignA[0] << ", Press 1 for " << worlddesignA[1] << ", or Press 2 for " << worlddesignA[2] << ", or Press 3 for " << worlddesignA[3] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (worlddesignA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 15 || money < 40000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 30 || money < 75000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 50 || money < 90000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 3 && (r < 30 || money < 50000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0)
			{

				r = r - 15;
				money = money - 40000;
				researchProcess();
				basiclore = "Basic Lore Building ($15,000)";
				basiclore2 = true;
				worlddesignA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && worlddesignA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 75000;
				researchProcess();
				openworld = "Open World ($25,000)";
				worlddesignA[choiceIndex] = "---";
				openworld2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && worlddesignA[choiceIndex - 1] == "---")
			{
				r = r - 50;
				money = money - 90000;
				researchProcess();
				daynight = "Day and Night Cycle (Cost: $30,000)";
				worlddesignA[choiceIndex] = "---";
				daynight2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 3 && worlddesignA[choiceIndex - 1] == "---")
			{
				r = r - 30;
				money = money - 50000;
				researchProcess();
				richbackstory = "Rich Backstory (Cost: $17,500)";
				worlddesignA[choiceIndex] = "---";
				richbackstory2 = true;
				researchstatus = true;
			}
			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}
	else if (researchchoice == 9) {
		cout << "Press 0 for " << soundA[0] << ", Press 1 for " << soundA[1] << ", or Press 2 for " << soundA[2] << "." << endl;
		cin >> choiceIndex;
		while (researchstatus == false) {
			if (soundA[choiceIndex] == "---")
			{
				cout << "You've already researched that." << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 0 && (r < 15 || money < 40000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;
			}
			else if (choiceIndex == 1 && (r < 25 || money < 60000))
			{

				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}
			else if (choiceIndex == 2 && (r < 45 || money < 100000))
			{
				cout << "You can't afford that!" << endl;
				researchstatus = true;

			}


			else if (choiceIndex == 0)
			{

				r = r - 15;
				money = money - 40000;
				researchProcess();
				monosound = "Mono Soundfont ($12,500)";
				monosound2 = true;
				soundA[choiceIndex] = "---";
				researchstatus = true;
			}
			else if (choiceIndex == 1 && soundA[choiceIndex - 1] == "---")
			{
				r = r - 25;
				money = money - 60000;
				researchProcess();
				stereosound = "Stereo Soundfont ($20,000)";
				soundA[choiceIndex] = "---";
				stereosound2 = true;
				researchstatus = true;
			}
			else if (choiceIndex == 2 && soundA[choiceIndex - 1] == "---")
			{
				r = r - 45;
				money = money - 100000;
				researchProcess();
				chiptone = "Soundtrack ($33,000)";
				soundA[choiceIndex] = "---";
				chiptone2 = true;
				researchstatus = true;
			}


			else
			{
				cout << "You can't research that because you haven't researched the item before it." << endl;
				researchstatus = true;

			}
		}
	}

}
void researchReport()
{
	for (int index = 1; index < 6; index++)
	{
		r = r + (int)(rand() % 4);
		cout << "You have " << r << " points." << endl;
		Sleep(1000);
		turnCheck();
	}
	gamecomplete = false;

}
void unlockAllResearch()
{

}
		

	int main()

	{
		bool debugcheat1 = false;
		string researchunlock = "";
		cout << "Welcome to Game Tycoon. Before you begin you need to select a name and your company name." << endl;
		Sleep(1000);
		cout << "What is your name?" << endl;
		getline(cin, name);
		if (name == "cheat") {
			r = r + 100000;
			money = money + 1000000;
			gamecomplete = true;
			cout << "Cheats activated. Activate all research unlocks?" << endl;
			cin >> researchunlock;
			// if (researchunlock == "yes") {

			// }
		}
		Sleep(500);
		cout << "What's the name of your company?" << endl;
		getline(cin, company);
		cout << name << ", you have 300 turns to build your company, " << company << ", into a successful video game developer. You have " << money << " dollars to begin with." << endl << "Your goal is to have 1.5 million dollars by the end of the game." << endl;


		while (gamestatus == false && researchstatus == false && wincheck == false && researchreportstatus == false)
		{

			Sleep(1000);




			cout << "This is the Main Menu. You can choose to create a new game or research something. (Use ""game"" to select game development, and use ""research"" to research something." << endl;
			cin >> playerchoice;
			if (check(playerchoice, "research"))
			{
				researchFunc();
			}
			else if (check(playerchoice, "game"))
			{
				gameDev();
			}
			else if (check(playerchoice, "report"))
			{
				if (gamecomplete == true)
					researchReport();
				else
					cout << "You haven't made any games recently." << endl;
			}
			else
			{
				cout << "Invalid response." << endl;
				gamestatus = false;
			}
		}
	}



	






	
