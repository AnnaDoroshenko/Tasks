#include <iostream>
#include <string>

std::string countAndSay (unsigned int num) {
    std::string resultString;
    std::string currentString;
    unsigned int currentCount;
    char currentChar;

    if (num <= 0) {
        std::cout << "Invalid string number";
        return "";
    }

    resultString = "1";
    for (unsigned int i = 1; i < num; i++) {
        std::cout << resultString << std::endl;
        currentString = "";
        const unsigned int stringSize = resultString.size();
        for (unsigned int i = 0; i < stringSize; ) {
            currentCount = 0;
            currentChar = resultString[i];
            do {
                currentCount++;
                i++;
            } while ((currentChar == resultString[i]) && (i < stringSize)); 
            currentString += std::to_string(currentCount) + currentChar;
        }
        resultString = currentString;
    };

    return resultString;
}

int main() {
    const unsigned num = 7;
    std::cout << countAndSay(num) << std::endl;

    return 0;
} 
