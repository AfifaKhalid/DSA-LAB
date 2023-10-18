#include <iostream>
#include <stack>

int main() {
    std::string inputString;
    char c;

    std::cout << "Enter a string: ";

    while (std::cin.get(c) && c != '\n') {
        inputString += c;
    }

    std::stack<char> charStack;

    for (size_t i = 0; i < inputString.size(); ++i) {
        charStack.push(inputString[i]);
    }

    std::string reversedString;
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    std::cout << "Reversed string: " << reversedString << std::endl;

    return 0;
}

