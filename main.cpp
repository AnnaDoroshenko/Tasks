#include <iostream>
#include <string>
/* #include <cstring> */

/* unsigned int countUniqueSubstring(std::string str) { */
/*     const unsigned int strSize = str.size(); */
/*     unsigned int begin = 0; */
/*     unsigned int end = 0; */
/*     unsigned int count = 0; */
/*     unsigned int start; */
/*     bool map[256]; */
/*      */
/*     memset(map, false, 256 * sizeof(bool)); */
/*  */
/*     if (strSize == 0) { */
/*         std::cout << "[Empty string] = "; */
/*         return count; */
/*     } */
/*         unsigned int currentCount; */
/*         do { */
/*             currentCount = 0; */
/*             do { */
/*                 if (end == strSize) { */
/*                     break; */
/*                 } */
/*                 map[str[end]] = true; */
/*                 end++; */
/*             } while (map[str[end]] != true); */
/*             std::cout << "begin=" << begin << std::endl; */
/*             std::cout << "end=" << end << std::endl; */
/*             currentCount = end - begin; */
/*             std::cout << "count=" << currentCount << std::endl; */
/*             if (currentCount > count) { */
/*                 count = currentCount; */
/*             } */
/*             for (unsigned int i = begin; i < end; i++) { */
/*                 if (str[i] == str[end]) { */
/*                     start = i + 1; */
/*                 } */
/*                 map[str[i]] = false; */
/*             } */
/*             map[str[end - 1]] = true; */
/*             begin = start; */
/*         } while (end < strSize); */
/*  */
/*     return count; */
/* } */

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
        for (unsigned int i = 0; i < resultString.size(); ) {
            currentCount = 0;
            currentChar = resultString[i];
            do {
                currentCount++;
                i++;
            } while (currentChar == resultString[i]); // FIXME: you go outta bounds here with i
            currentString += std::to_string(currentCount) + currentChar;
        }
        resultString = currentString;
    };

    return resultString;
}

int main() {
    // const std::string str = "";
    /* const std::string str = "abcdaefg"; */
    /* const std::string str = "ababcaac"; */
    /* const std::string str = "abcdbcfg"; */
    /* std::cout << "count = " << countUniqueSubstring(str) << std::endl; */
    const unsigned num = 7;
    std::cout << countAndSay(num) << std::endl;

    return 0;
} 
