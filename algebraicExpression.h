/*algebraicExpression.h
 *
 * Salvatore D'Armetta
 * 5/11/17
 *
 * header file of the algebraic expression class
 * used for declaring constructors and methods to
 * convert and evaluate an in-fix algebraic expression.
 *
 */

#include "stack.h"

class AlgebraicExpression{

	friend ostream& operator<<(ostream &, const AlgebraicExpression &);	
	friend istream& operator>>(istream &, AlgebraicExpression &);

public:

	AlgebraicExpression();
	AlgebraicExpression(string, string);
	AlgebraicExpression(const AlgebraicExpression &);

	void convert();
	int evaluate();

	int precedence(const char &);
	void inputExpression();

private:

	string infix;
	string postfix;

};
