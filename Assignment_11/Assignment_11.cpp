// Assignment_11.cpp : Defines the entry point for the console application.
//
// header files
#include "stdafx.h"
#include <iostream>
#include "Header.h" // this is my personal header file that holds 3 functions for this assignment
#include <cstdlib>
#include <ctime>
#include <string>

// uses the standard namespace
using namespace std;

// main
int main()
{
	srand(static_cast<unsigned int>(time(0))); // seeds random number generator
	string playerName; // variable to hold playerName
	int playerLevel; // variable to hold playerLevel
	int levelDifficulty = rand() % 150; // variable to hold level difficulty, initialize at a random number between 1 and 150
	bool victoryCheck; // variable to hold true or false
	int levelNum = 1; // variable to hold the current level of the dungeon you are on, starts at 0
	cout << "Welcome to the game show: Pick. Your. Door!\n";
	cout << "What is you name?\n";
	cin >> playerName; //let player pick a name
	cout << "Please Choose a number between 1 and 100. This number will tell us how many doors you have, or have planned on opening.\n";
	cin >> playerLevel; // let player pick their starting player level
	if (playerLevel >= 101) // ensures that the number selected is valid
	{
		playerLevel = validNum(playerLevel); // goes to One.cpp file and runs the validNum function passing playerLevel as the variable and assigns the return value to playerLevel variable
	}
	cout << endl << endl << "The Doors have been chosen!" << endl;

	do // do loop, so it always runs at least once
	{
		cout << "Number of doors you have opened: " << playerLevel << endl; 
		cout << "Current Door: " << levelNum << endl; 
		cout << "Level of danger: " << levelDifficulty << endl; 
		victoryCheck = compare(playerLevel, levelDifficulty); // check to see if player beats this floor by going to One.cpp and using the compare function sending playerLevel and levelDifficulty for comparison
		cout << endl; 
		if (victoryCheck == true) // if player did win
		{
			cout << "You Opened Door " << levelNum << endl; // display the level they cleared
			playerLevel = levelUp(playerLevel, 1); // level the player up by 1 by sending playerLevel and 1 into the levelUp function from one.cpp which adds the values together
			levelNum++; 
			levelDifficulty = rand() % 151; 
		}
		else
		{
			cout << "Your door had nothing\n\n"; //End the game
		}
		if (playerLevel == 151) 
		{
			cout << "Sorry it seems the door is locked,Could this be a good or a bad sign? :)!\n\n";
			victoryCheck = false; // make victoryCheck false, so we can drop out of the loop
		}
	} while (victoryCheck == true); // while victoryCheck is true keep running the loop

									// print out final stastics
	cout << "Final Statistics:\n";
	cout << "Number of doors that you opened: " << playerLevel +1  << endl;
	cout << "Current Door count: " << levelNum << endl;
	cout << "Thanks for Playing!\n";
	system("pause");
	return 0;
}