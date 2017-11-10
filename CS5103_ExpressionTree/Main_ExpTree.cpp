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
#include <algorithm>

struct node {
	char data;
	node* left = nullptr;
	node* right = nullptr;
};

bool isOperator(char op);
void preorder(node * leaf);
void inorder(node * leaf);
void postorder(node * leaf);
std::string shuntingYard(std::string rpnExpr);

int main() {
	std::string expr = "(a + b * c) + ((d * e + f) * g)";

	std::stack<node*> treeStack;

	std::string rpnExpr = shuntingYard(expr);

	for (int i = 0; i < rpnExpr.size(); i++) {
		if (!isOperator(rpnExpr[i])) {
			node *newNode = new node;
			newNode->data = rpnExpr[i];
			treeStack.push(newNode);
		}

		else if (isOperator(rpnExpr[i])) {
			node *newNode = new node;
			newNode->data = rpnExpr[i];
			newNode->right = treeStack.top();
			treeStack.pop();
			newNode->left = treeStack.top();
			treeStack.pop();
			treeStack.push(newNode);
		}
	}
	
	std::cout << "Original Expression:\n" << expr 
		<< "\nParentheses are removed in the output below.\n\n";
	std::cout << "Preorder:" << std::endl;
	preorder(treeStack.top());
	std::cout << "\n\nInorder:" << std::endl;
	inorder(treeStack.top());
	std::cout << "\n\nPostorder:" << std::endl;
	postorder(treeStack.top());
	std::cout << "\n\n";

	return 0;
}

bool isOperator(char op) {
	if (op == '+' || op == '-' ||
		op == '*' || op == '/')
		return true;
	else
		return false;
}

void preorder(node * leaf) {
	if (leaf != nullptr) {
		std::cout << leaf->data << " ";
		preorder(leaf->left);
		preorder(leaf->right);
	}
};

void inorder(node * leaf) {
	if (leaf != nullptr) {
		inorder(leaf->left);
		std::cout << leaf->data << " ";
		inorder(leaf->right);
	}
};

void postorder(node * leaf) {
	if (leaf != nullptr) {
		postorder(leaf->left);
		postorder(leaf->right);
		std::cout << leaf->data << " ";
	}
};

std::string shuntingYard(std::string expr) {
	std::vector<char> output;
	std::stack<char> stack;
	std::string outputString;

	std::map<char, int> opPriority;
	opPriority['+'] = 10;
	opPriority['-'] - 10;
	opPriority['*'] = 20;
	opPriority['/'] - 20;

	// Remove whitespace from the expression
	expr.erase(std::remove_if(expr.begin(), expr.end(), isspace), expr.end());

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
		outputString += output[i];

	return outputString;

}
