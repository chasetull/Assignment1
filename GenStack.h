/*
002297037
Chase Tullar
CPSC350
Assignment3
10/7/19
*/

//generic stack class TempStack
#include <iostream>
#include <fstream>
using namespace std;

template <class T> class GenStack //template
{
	public:
		//setup
		GenStack();
		GenStack(int setSize);
		~GenStack();

		//func
		void push(T);
		T pop();
		T peek();

		bool isFull();
		bool isEmpty();

		//vars
		int size;
		int top = -1;
		string temp;

		//init array ptr
		T *myArray;
};

//implement

template <class T> GenStack<T>::GenStack()
{
	//constr
}

template <class T> GenStack<T>::GenStack(int setSize)
{
	//copy constr
	myArray = new T [setSize];
	size = setSize;
	top = -1;
}

template <class T> GenStack<T>::~GenStack()
{
	//destr
	//delete [] myArray
}

template <class T> void GenStack<T>::push(T ch) //push method
{
	//push
	if (!GenStack<T>::isFull())
	{
		top += 1;
		myArray[top] = ch;
	}

}

template <class T> bool GenStack<T>::isEmpty() //check empty
{
	//pop
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//return (top == -1);
}

template <class T> bool GenStack<T>::isFull() //check full
{
	if ((top + 1) == size)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

template <class T> T GenStack<T>::pop() //pop
{
	return myArray[top--];
}

template <class T> T GenStack<T>::peek() //peek
{
	return myArray[top];
}



