// Converts infix arithmetic operations to postfix
// Implements the algorithm from this description:
// http://www.oxfordmathcenter.com/drupal7/node/628

#include <iostream>
#include <stack>

using namespace std;

// OpInfo describes an operator's character and priority.
// zero-priority operators are + and -.
struct OpInfo {
	char opChar;
	int priority = 0;
};

// ShuntMather is a dumb class. Just make one and call ProcessInput().
// Then the user enters an algebraic expression followed by " q" and hits Enter.
class ShuntMather {
public:
	// process user input
	void ProcessInput() {
		string input;
		for (cin >> input; input != "q"; cin >> input) {
			char c = input.at(0);

			if (IsValidOp(c)) {
				OpInfo op;
				op.opChar = c;
				DetPriority(op);
				ProcessOp(op);
			} else if (IsParen(c)){
				ProcessParen(c);
			} else {
				cout << input << " ";
			}
		}
		while (!operators.empty()) {
			cout << operators.top().opChar << " ";
			operators.pop();
		}
		cout << endl;
	}
private:
	// Priority of *,/ is 1. Priority of ^ is 2. This is due to the order of
	// arithmetic operations.
	void DetPriority(OpInfo& op) {
		if (op.opChar == '*' ||
			op.opChar == '/')
			op.priority = 1;
		else if (op.opChar == '^')
			op.priority = 2;
		else if (IsParen(op.opChar))
			op.priority = 3;
		// otherwise, the struct constructor took care of priority = 0
	}

	bool IsValidOp(char c) {
		return opChars.find(c) != string::npos;
	}

	// print the top, then pop it
	void PrintPop() {
		cout << operators.top().opChar << " ";
		operators.pop();
	}		

	// This handles comparing priority and printing the operator along the way,
	// if necessary.
	void ProcessOp(OpInfo op) {
		if (!operators.empty() && !IsParen(operators.top().opChar)) {
			if (op.priority <= operators.top().priority) {
				PrintPop();
			}
		}
		operators.push(op);
	}

	void ProcessParen(char paren) {
		if (paren == '(') {
			OpInfo opParen;
			opParen.opChar = paren;

			operators.push(opParen);
		} else { // it's a ')'
			// do the operations until you encounter the open paren
			while(operators.top().opChar != '(') {
				PrintPop();
			}

			// then throw it out
			operators.pop();
		}
	}
	
	bool IsParen(char c) {
		return c == '(' || c == ')';
	}

	stack<OpInfo> operators;
	static const string opChars;
};

const string ShuntMather::opChars = "+-*/^";

int main() {
	ShuntMather mather;
	mather.ProcessInput();
}
