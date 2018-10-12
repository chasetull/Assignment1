/*
002297037
Chase Tullar
CPSC350
Assignment3
10/7/19
*/

//main for GenStack
#include <iostream>
#include <fstream>
#include "GenStack.h"
using namespace std;

int main(int argc, char **argv)
{
	//main
	string path;
	string temp;
	char popd;
	ifstream openf;
	int lineIncr = 0;

	GenStack <char> myStack(10); //init array

	cout << "Welcome to my syntax checker" << endl;

	cout << "Enter filepath (testF.txt): " << endl;
	cin >> path;

	while (path != "testF.txt")
	{
		cout << "Wrong filepath, try again" << endl;
		cin >> path;
	}

	openf.open(path);

	if (openf.is_open()) //open file
	{
		while(getline(openf, temp))
		{
			lineIncr++;

			for (char c : temp)
			{
				//in file look at chars

				if (c == '(' || c == '[' || c == '{')
				{
					myStack.push(c); //push to stack

				}

				else if (c == ')' || c == ']' || c == '}') //check if last elem is complete
				{
					popd = myStack.pop(); //pop

					if (popd == c)
					{
						cout << "Error" << endl; //prob dont need
					}

					else if (popd == '(' && c != ')')
					{
						cout << "You entered " << popd << " with no ')'" << endl;
						cout << "Incorrect entry : " << c << " at line : " << lineIncr << endl;
					}

					else if (popd == '[' && c != ']')
					{
						cout << "You entered " << popd << " with no ']'" << endl;
						cout << "Incorrect entry : " << c << endl;
					}

					else if (popd == '{' && c != '}')
					{
						cout << "You entered " << popd << " with no '}'" << endl;
						cout << "Incorrect entry : " << c << endl;
					}

					else
					{
						myStack.push(c); //if last elem matches add to stack
					}

				}

				else
				{
					continue;
				}
			}

			lineIncr++; //increment line num
		}

		if (popd != ')' || popd != ']' || popd != '}') //checking end of file
		{
			if (myStack.peek() == '(')
			{
				cout << "Reached end of file. Missing : )" << endl;
			}

			else if (myStack.peek() == '[')
			{
				cout << "Reached end of file. Missing : ]" << endl;
			}

			else if (myStack.peek() == '{')
			{
				cout << "Reached end of file. Missing : }" << endl;
			}

			else if (myStack.peek() != '(' || myStack.peek() != '[' || myStack.peek() != '{')
			{
				cout << "SUCCESSFUL SYNTAX" << endl;
			}
		}

	}
}