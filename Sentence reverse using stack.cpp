#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string inputString;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, inputString);

    std::stack<std::string> wordStack;

    std::istringstream iss(inputString);
    std::string word;

    while (iss >> word) {
        wordStack.push(word);
    }

    std::string reversedSentence;

    while (!wordStack.empty()) {
        reversedSentence += wordStack.top() + " ";
        wordStack.pop();
    }

    if (!reversedSentence.empty()) {
        reversedSentence = reversedSentence.substr(0, reversedSentence.length() - 1);
    }

    std::cout << "Reversed sentence: " << reversedSentence << std::endl;

    return 0;
}

