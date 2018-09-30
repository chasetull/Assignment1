//GAME OF LIFE
#include <iostream>
#include <fstream>
#include "Assignment2.h"
using namespace std;

/*
g++ -o ass2 Assignment2.h Assignment2Setup.cpp newBoard.h newB.cpp Assignment2_Main.cpp
*/


int main()
{
	//vars
	string boardPath;
	int numR;
	int numC;
	float dens;
	char answer;
	InitBoard ib;

	cout << "Welcome to the Game of Life" << endl;
	cout << "Do you want a random board configuration?(y/n) : " << endl;
	cin >> answer;

	while (answer != 'y' && answer != 'n')
	{
		cout << "Wrong input, please type y/n : " << endl;
		cin >> answer;
	}

	if (answer == 'y')
	{
		//ask for dimensions and density
		cout << "Enter an int for the number of rows: " << endl;
		cin >> numR;

		//error check
		while (numR > 10)
		{
			cout << "Error input too large, try again" << endl;
			cin >> numR;
		}

		cout << "Enter an int for the number of collumns: " << endl;
		cin >> numC;

		//error check
		while (numC > 10)
		{
			cout << "Error input too large, try again" << endl;
			cin >> numC;
		}

		cout << "Enter a decimal between 0 and 1: " << endl;
		cin >> dens;

		//CHECK DECIMAL
		while (dens > 0.9 || dens < 0.1)
		{
			cout << "Error input too large, try again" << endl;
			cin >> dens;
		}

		//rand construct
		double r;
		int countP = 1;
		//temp str
		string randBoard;

		//create new board
		char** gameBoard = new char*[numR];
		for (int i = 0; i < numR; i++)
		{
			gameBoard[i] = new char[numC];
		}

		cout << "Random board being generated..." << endl;

		for (int i = 0; i < numR; ++i)
		{
			for (int j = 0; j < numC; ++j)
			{
				//random number for density
				r = ((double) rand() / (RAND_MAX));

				if (r < dens)
				{
					gameBoard[i][j] += 'X';
				}

				else
				{
					gameBoard[i][j] += '-';
				}

				//add to str
				randBoard += gameBoard[i][j];

			}
		}

		//print board
		for (int i = 0; i < numR; i++)
		{
			//second for
			for (int j = 0; j < numC; j++)
			{
				//printing formatted
				cout << gameBoard[i][j];
			}
			//new line
			cout << "\n";
		}


	}

	else if (answer == 'n')
	{
		cout << "Enter the text file path for the game board : " << '\n' << "(initB.txt)" << endl;
		cin >> boardPath;

		//if statement check
		if (boardPath != "initB.txt")
		{
			cout << "Input error, try again: " << endl;
			cin >> boardPath; 
		}

		//create object
		ib.setGame(boardPath);
		
		//ib.calcNext(this->gameBoard);


	}

	return 0;
}