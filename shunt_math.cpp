// Converts infix arithmetic operations to postfix

#include <iostream>
#include <stack>

using namespace std;
struct OpInfo {
	char opChar;
	int priority = 0;
};

class ShuntMath {
public:
	void ProcessInput() {
		char c;
		for (cin >> c; c != 'q'; cin >> c) {
			if (IsValidOp(c)) {
				OpInfo op;
				op.opChar = c;
				DetPriority(op);
				ProcessOp(op);
			} else {
				cout << c << " ";
			}
		}
		while (!operators.empty()) {
			cout << operators.top().opChar << " ";
			operators.pop();
		}
		cout << endl;
	}
private:
	void DetPriority(OpInfo& op) {
		if (op.opChar == '*' ||
			op.opChar == '/')
			op.priority = 1;
	}
	bool IsValidOp(char c) {
		return opChars.find(c) != string::npos;
	}
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

const string ShuntMath::opChars = "+-*/";

int main() {
	ShuntMath mather;
	mather.ProcessInput();
}
