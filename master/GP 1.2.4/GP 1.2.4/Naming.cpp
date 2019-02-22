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
using namespace std;
cout << "Welcome to Game Tycoon. Before you begin you need to select a name and your company name." << endl;
Sleep(1000);
cout << "What is your name?" << endl;
getline(cin, name);

Sleep(500);
cout << "What's the name of your company?" << endl;
getline(cin, company);
cout << name << ", you have 150 turns to build your company, " << company << ", into a successful video game developer. You have " << money << " dollars to begin with." << endl << "Your goal is to have 1.5 million dollars by the end of the game." << endl;
