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
			if (IsValidOp(input.at(0))) {
				OpInfo op;
				op.opChar = input.at(0);
				DetPriority(op);
				ProcessOp(op);
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
		// otherwise, the struct constructor took care of priority = 0
	}

	bool IsValidOp(char c) {
		return opChars.find(c) != string::npos;
	}

	// This handles comparing priority and printing the operator along the way,
	// if necessary.
	void ProcessOp(OpInfo op) {
		if (!operators.empty()) {
			if (op.priority <= operators.top().priority) {
				cout << operators.top().opChar << " ";
				operators.pop();
			}
		}
		operators.push(op);
	}
	
	stack<OpInfo> operators;
	static const string opChars;
};

const string ShuntMather::opChars = "+-*/^";

int main() {
	ShuntMather mather;
	mather.ProcessInput();
}
