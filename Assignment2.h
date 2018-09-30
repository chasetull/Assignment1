//.h file for Assignment2_main

#include <iostream>
using namespace std;
//class for board setup?
class InitBoard
{
	public:
		//setup
		InitBoard();
		InitBoard(int row, int coll);
		~InitBoard();

		//functs
		void setGame(string boardPath);
		//unused
		void calcNext(char** gameBoard); //maybe char** gB?

		//vars
		char alive = 'X';
		char dead = '-';
		char** gameBoard;
		int row;
		int coll;
		char* point;
		char* neigh;
		int countN;
};