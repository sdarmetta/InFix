/*driver.cpp
 *
 * Salvatore D'Armetta
 *
 * driver program that instantiates an object
 * of AlgebraicExpression, asks for an infix expression
 * and then converts and evaluates the postfix expression.
 *
 */

#include "algebraicExpression.h"

int main(){

	//objects and variables
	AlgebraicExpression expression;
	int result;
	char contin = 'y';

	cout << "Welcome to the Post-Fix calculator!" << endl;

	//loop while user wishes to coninue
	while(contin == 'y'){
		
		cout << "Enter an expression: ";
		cin >> expression;

		expression.convert();	//conver input infix expression to postfix

		result = expression.evaluate();	//evaluate postfix expression

		cout << expression;	//output infix and postfix expression

		cout << "The result is: "  << result << endl;	//output the result

		cout << "Continue? (y for yes, n for no): ";
		cin >> contin;
	}
}

