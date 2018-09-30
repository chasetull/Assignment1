#include <iostream>
#include <fstream>
#include "Assignment2.h"
using namespace std;

InitBoard::InitBoard()
{
	//constructor
}

InitBoard::InitBoard(int row, int coll)
{
	//construct 2d array
	char** gameBoard = new char*[row];
	for (int i = 0; i < row; i++)
	{
		gameBoard[i] = new char[coll];
	}
}

InitBoard::~InitBoard()
{
	//destroy array
	/*
	for (int i = 0; i < row; i++)
	{
		//deleting chars on board
		delete[] gameBoard[i];

	}
	
	delete[] gameBoard;
	*/
		
	cout << "array destroyed" << endl;
}


//function to setup game board
void InitBoard::setGame(string boardPath)
{
	//str to store input
	string getBounds;
	string temp;
	//substr
	string revTemp;
	//counters for X and - stats
	int countX = 0;
	int countD = 0;

	//open file from path
	ifstream openB;
	openB.open(boardPath);

	if (openB.is_open())
	{
		while (getline(openB, getBounds))
		{
			//cout << "line to add: " << getBounds << endl;
			for (char c : getBounds)
			{
				//adding chars to temp str
				temp += c;

				//count X
				if (c == 'X')
				{
					//count num of alive
					++countX;
				}

				else if (c == '-')
				{
					//count dead
					++countD;
				}

			}

		}

		//changing str value to int
		this->row = temp[0] - '0';
		this->coll = temp[1] - '0';
		
		//init array with new bounds
		char** gameBoard = new char*[row];
		for (int i = 0; i < row; i++)
		{
			gameBoard[i] = new char[coll];
		}

		//make new string, delete first 2 elements
		revTemp = temp.substr(2, 35);

		//counter for revTemp[]
		int countR = 0;

		//add chars in substr to gameBoard using nested for
		for (int i = 0; i < row; i++)
		{
			//second for
			for (int j = 0; j < coll; j++)
			{
				//placing chars on board
				gameBoard[i][j] = revTemp[countR];

				//incrementing counter
				++countR;
			}
		}

		cout << "Initial generation:" << endl;

		//print game board to user
		for (int i = 0; i < row; i++)
		{
			//second for
			for (int j = 0; j < coll; j++)
			{
				//printing formatted
				cout << gameBoard[i][j];
			}
			//new line
			cout << "\n";
		}

		//print stats
		cout << "number alive: " << countX << endl;
		cout << "number dead: " << countD << endl;

		//close file
		openB.close();
	}

	//compute new gen??
	char* point = NULL;
	char* neigh = NULL;
	int countN = 0;

	//parse thru array to check neighbors
}


//calc next gen function

void InitBoard::calcNext(char** gameBoard)
{
	//compute next gen
	//cout << "GB @ : " << gameBoard[0][3] << endl;


}
