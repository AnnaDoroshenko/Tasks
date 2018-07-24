#include <iostream>
#include <string>
#include <cstring> // for memset()

unsigned int countUniqueSubstring(std::string str) {
    const unsigned int strSize = str.size();
    if (strSize == 0) {
        std::cout << "[Empty string] = ";
        return 0;
    }

    unsigned int begin = 0;
    unsigned int end = 0;
    unsigned int count = 0;
    bool map[256];
    memset(map, false, 256 * sizeof(bool));

    do {
        do {
            map[str[begin]] = true;
            begin++;
        } while ((begin < strSize) && (map[str[begin]] == false));

        const unsigned int currentCount = begin - end;
        if (currentCount > count) {
            count = currentCount;
        }

        if (begin >= strSize) {
            return count;
        }
        for (unsigned int i = end; i < begin; i++) {
            if (str[i] == str[begin]) {
                end = i + 1;
                break;
            } else {
                map[str[i]] = false;
            }
        }
    } while (true);
}

int main() {
    const std::string str = "abcadbcfbg";
    std::cout << "count = " << countUniqueSubstring(str) << std::endl;

    return 0;
} 
