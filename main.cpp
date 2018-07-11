#include <iostream>
// #include <string>
#include <cstring>

unsigned int countUniqueSubstring(std::string str) {
    unsigned int begin = 0;
    unsigned int end = 0;
    unsigned int count = 0;
    unsigned int start;
    bool map[256];
    
    memset(map, 0, 256 * sizeof(bool));

    if (str.size() != 0) {
        unsigned int currentCount;
        do {
            currentCount = 0;
            while (end != str.size()) {
                if (map[str[end]]) {
                    for (unsigned int i = begin; i < end; i++) {
                        if (str[i] == str[end]) {
                            start = i + 1;
                            break;
                        }
                    }
                    break;
                }
                map[str[end]] = 1;
                end++;
            }
            currentCount = end - begin;
            if (currentCount > count) {
                count = currentCount;
            }
            for (unsigned int i = begin; i < end; i++) {
                map[str[i]] = 0;
                std::cout << str[i] << " ";
            }
            std::cout << std::endl;
            begin = start;
            std::cout << begin << std::endl;
        } while (end != str.size());
    } else {
        std::cout << "[Empty string] = ";
    }

    return count;
}

int main() {
    // const std::string str = "";
    // const std::string str = "abcdaefg";
    const std::string str = "ababcaac";
    std::cout << "count = " << countUniqueSubstring(str) << std::endl;

    return 0;
} 
