/*algebraicExpression.cpp
 *
 * Salvatore D'Armetta
 *
 * source file for the AlgebraicExpression class
 * defining all constructor and methods of the class
 * necessary to convert and evaluate an infix algebraic
 * expression.
 *
 */

#include "algebraicExpression.h"

//default constructor
AlgebraicExpression::AlgebraicExpression(){

	infix = "";
	postfix = "";
}

//custom constructor
AlgebraicExpression::AlgebraicExpression(string i, string p){

	infix = i;
	postfix = p;
}

//copy constructor
AlgebraicExpression::AlgebraicExpression(const AlgebraicExpression &a){

	infix = a.infix;
	postfix = a.postfix;
}

//method to convert an algebraic expression from infix to postfix
void AlgebraicExpression::convert(){

	Stack<char> operatorStack;
	char c;
	postfix = "";

	//while i is less than the infix expression length
	for(int i = 0; i < infix.length(); i++){

		char ch = infix.at(i);	//set ch to i element of infix expression
		c = ch;

		if(ch >= '0' && ch <= '9'){	//if ch is an operand, set c equal to o
			c = 'o';
		}
		
			

		switch(c){

			case 'o':	//if ch is an operand, append
				postfix += ch;
				break;
			
			case '(':
				operatorStack.push(ch);		//if ch is open parenthesis, push onto stack
				break;

			case ')':
				while(operatorStack.getTop() != '('){	//if ch is closed parenthesis, append top of stack
									//until stack reaches open parenthesis
					
					postfix += operatorStack.getTop();
					operatorStack.pop();
				}
				operatorStack.pop();	//pop open parenthesis off stack
				break;

			/* if ch is an operator, while the stack is empty && the top of the stack is not an open parenthesis
			 * && the precedence of ch is less than or equal to top of the stack, pop top of the stack
			 * and append to postfix expression 
			 * push operator onto stack
			 */
			case '+':
				while((!operatorStack.isEmpty()) && (operatorStack.getTop() != '(') && (precedence(ch) <= precedence(operatorStack.getTop()))){

					postfix += operatorStack.getTop();
					operatorStack.pop();
				}
				operatorStack.push(ch);
				break;

			case '-':
				while((!operatorStack.isEmpty()) && (operatorStack.getTop() != '(') && (precedence(ch) <= precedence(operatorStack.getTop()))){
					
					postfix += operatorStack.getTop();
					operatorStack.pop();
				}
				operatorStack.push(ch);
				break;

			case '*':
				while((!operatorStack.isEmpty()) && (operatorStack.getTop() != '(') && (precedence(ch) <= precedence(operatorStack.getTop()))){
					postfix += operatorStack.getTop();
					operatorStack.pop();
				}
				operatorStack.push(ch);
				break;

			case '/':
				while((!operatorStack.isEmpty()) && (operatorStack.getTop() != '(') && (precedence(ch) <= precedence(operatorStack.getTop()))){
			
					postfix += operatorStack.getTop();
					operatorStack.pop();
				}
				operatorStack.push(ch);
				break;
				
		}
	}

	//pop rest of the stack and append
	while(!operatorStack.isEmpty()){
		
		postfix += operatorStack.getTop();
		operatorStack.pop();
	}

}

//method to evaluate a postfix expression
int AlgebraicExpression::evaluate(){

	Stack<int> operandStack;
	int operand;
	int operand1, operand2;
	int result;

	//loop while i is less than postfix expression length
	for(int i = 0; i < postfix.length(); i++){

		char ch = postfix.at(i);	//set ch to i element of postfix string

		if(ch >= '0' && ch <= '9'){	//if operand
			
			operand = ch - '0';	
			operandStack.push(operand);	//push numeric value of operand onto stack
		}
		else{		//if operator
			operand2 = operandStack.getTop();	//pop top two items off of the stack
			operandStack.pop();
			operand1 = operandStack.getTop();
			operandStack.pop();
		
			switch(ch){		//find result of operation

				case '+':
					result = operand1 + operand2;
					break;
				case '-':
					result = operand1 - operand2;
					break;
				case '*':
					result = operand1 * operand2;
					break;
				case '/':
					result = operand1 / operand2;
					break;
			}
			
			operandStack.push(result);	//push result onto stack
		}
	}

	return(operandStack.getTop());	//return the result
}

//method to determine the precedence of an operator
int AlgebraicExpression::precedence(const char &op){

	int precedence;

	switch(op){

		case '+':
		case '-':

			precedence = 1;
			break;

		case '*':
		case '/':

			precedence = 2;
			break;
	}

	return precedence;
}

//method to input an infix expression
void AlgebraicExpression::inputExpression(){

	cin >> infix;
}

//overloaded input/output operators
ostream& operator<<(ostream &o, const AlgebraicExpression &a){

	o << "Infix Expression: " << a.infix << endl;
	o << "Postfix Expression: " << a.postfix << endl;

	return(o);
}

istream& operator>>(istream &i, AlgebraicExpression &a){

	a.inputExpression();

	return(i);
}






