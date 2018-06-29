#include <iostream>
#include <string>
#include <cstring>

unsigned int countAndSay(std::string str) {
    unsigned int begin = 0;
    unsigned int end = 0;
    unsigned int count = 0;
    bool map[256];
    
    memset(map, 0, 256 * sizeof(bool));

    if (str.size() != 0) {
        unsigned int currentCount;
        do {
            currentCount = 0;
            do {
                map[str[end]] = 1;
                end++;
            } while ((map[str[end]] != 1) || (end != str.size()));
            currentCount = end - begin;
            if (currentCount > count) {
                count = currentCount;
            }
            for (unsigned int i = begin; i < end; i++) {
                map[str[i]] = 0;
            }
            begin = end;
        } while (end != str.size());
    } else {
        std::cout << "[Empty string] = ";
    }

    return count;
}

int main() {
    // const std::string str = "";
    const std::string str = "ababcaac";
    std::cout << "count = " << countAndSay(str) << std::endl;

    return 0;
} 
