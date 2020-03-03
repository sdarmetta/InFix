/*stack.h
 *
 * Salvatore D'Armetta
 * 5/11/17
 *
 * stack header file to define a stack template class
 * used to create a operand or operator stack
 * for converting and evaluating algebraic expressions
 */

#include<iostream>
#include<vector>
using namespace std;

//creat a template class
template <class T>
class Stack{

public:

	Stack(){}	//default constructor

	void push(const T &item){	//push data onto stack
		data.push_back(item);
	}

	void pop(){			//pop data off the stack
		data.pop_back();
	}

	bool isEmpty(){			//check if stack is empty
		return data.empty();
	}

	T getTop(){		//return data item at top of the stack

		return(data.back());
	}

private:

	//data members
	vector<T> data;

};



