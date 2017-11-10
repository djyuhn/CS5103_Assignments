/**
CS5103 - Assignment 2 Expression Tree

@author DJ Yuhn
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include<algorithm>

bool isOperator(char op);

int main() {
	std::vector<char> output;
	std::stack<char> stack;
	std::string expr = "(a + b * c) + ((d * e + f) * g)";

	// Remove whitespace from the expression
	expr.erase(std::remove_if(expr.begin(), expr.end(), isspace), expr.end());
	
	std::map<char, int> opPriority;
	opPriority['+'] = 10;
	opPriority['-'] - 10;
	opPriority['*'] = 20;
	opPriority['/'] - 20;

	// Gather the characters
	for (int i = 0; i < expr.size(); i++) {
		
		// If character is operator
		if (isOperator(expr[i])) {
			char o1 = expr[i];

			if (!stack.empty()) {
				char o2 = stack.top();

				while (isOperator(o2) && (opPriority[o1] <= opPriority[o2])) {
					// Pop o2 and on to output
					stack.pop();
					output.push_back(o2);

					if (!stack.empty())
						o2 = stack.top();

					else
						break;
				}
			}

			stack.push(o1);
		}

		// If character is '('
		else if (expr[i] == '(') {
			stack.push(expr[i]);
		}

		// If character is ')'
		else if (expr[i] == ')') {
			char topChar = stack.top();
			while (stack.top() != '(') {
				output.push_back(topChar);
				stack.pop();
				if (stack.empty())
					break;
				topChar = stack.top();
			}

			if (!stack.empty())
				stack.pop();
		}

		// If character is number or letter
		else
			output.push_back(expr[i]);


	}

	while (!stack.empty()) {
		char restChar = stack.top();

		output.push_back(restChar);

		stack.pop();
	}

	for (int i = 0; i < output.size(); i++)
		std::cout << output[i];


	system("pause");


	return 0;
}

bool isOperator(char op) {
	if (op == '+' || op == '-' ||
		op == '*' || op == '/')
		return true;
	else
		return false;
}
