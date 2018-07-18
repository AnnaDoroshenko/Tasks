#include <iostream>
#include <string>
/* #include <cstring> */

unsigned int countUniqueSubstring(std::string str) {
    const unsigned int strSize = str.size();
    unsigned int begin = 0;
    unsigned int end = 0;
    unsigned int count = 0;
    unsigned int start;
    bool map[256];

    memset(map, false, 256 * sizeof(bool));

    if (strSize == 0) {
        std::cout << "[Empty string] = ";
        return count;
    }
        unsigned int currentCount;
        do {
            currentCount = 0;
            do {
                if (end == strSize) {
                    break;
                }
                map[str[end]] = true;
                end++;
            } while (map[str[end]] != true);
            std::cout << "begin=" << begin << std::endl;
            std::cout << "end=" << end << std::endl;
            currentCount = end - begin;
            std::cout << "count=" << currentCount << std::endl;
            if (currentCount > count) {
                count = currentCount;
            }
            for (unsigned int i = begin; i < end; i++) {
                if (str[i] == str[end]) {
                    start = i + 1;
                }
                map[str[i]] = false;
            }
            map[str[end - 1]] = true;
            begin = start;
        } while (end < strSize);

    return count;
}

int main() {
    // const std::string str = "";
    /* const std::string str = "abcdaefg"; */
    /* const std::string str = "ababcaac"; */
    const std::string str = "abcdbcfg";
    std::cout << "count = " << countUniqueSubstring(str) << std::endl;

    return 0;
} 
