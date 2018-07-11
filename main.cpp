#include <iostream>
// #include <string>
#include <cstring>

unsigned int countUniqueSubstring(std::string str) {
    const unsigned int strSize = str.size();
    unsigned int begin = 0;
    unsigned int end = 0;
    unsigned int count = 0;
    unsigned int start;
    bool map[256];
    
    memset(map, 0, 256 * sizeof(bool));

    if (strSize != 0) {
        unsigned int currentCount;
        do {
            currentCount = 0;
            do {
                if (end == strSize) {
                    break;
                }
                map[str[end]] = 1;
                end++;
            } while (map[str[end]] != 1);
            currentCount = end - begin;
            if (currentCount > count) {
                count = currentCount;
            }
            for (unsigned int i = begin; i < end; i++) {
                if (str[i] == str[end]) {
                    start = i + 1;
                }
                map[str[i]] = 0;
            }
            map[str[end - 1]] = 1;
            begin = start;
        } while (end < strSize);
    } else {
        std::cout << "[Empty string] = ";
    }

    return count;
}

int main() {
    // const std::string str = "";
    /* const std::string str = "abcdaefg"; */
    const std::string str = "ababcaac";
    std::cout << "count = " << countUniqueSubstring(str) << std::endl;

    return 0;
} 
