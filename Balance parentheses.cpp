#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& expression) {
    std::stack<char> charStack;
    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            charStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (charStack.empty()) {
                return false;
            }
            char top = charStack.top();
            charStack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return charStack.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isBalanced(expression)) {
        std::cout << "Balanced parentheses" << std::endl;
    } else {
        std::cout << "Unbalanced parentheses" << std::endl;
    }

    return 0;
}

