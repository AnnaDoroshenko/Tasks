#include <iostream>
/* #include <stdlib.h> // for srand(), rand() */
/* #include <time.h> // for time() */


int main() {
    srand(time(0)); // for automatic random number generation
    unsigned int count = 0;
    unsigned int temp = 0;
    while (count < 100) {
        const unsigned int LENGTH = 1 + rand() % 100;
        std::cout << LENGTH << std::endl;
        const unsigned int CHUNK_1 = 1 + rand() % LENGTH;
        std::cout << CHUNK_1 << std::endl;
        const unsigned int CHUNK_2 = 1 + rand() % (LENGTH - CHUNK_1);
        std::cout << CHUNK_2 << std::endl;
        const unsigned int CHUNK_3 = LENGTH - (CHUNK_1 + CHUNK_2);
        std::cout << CHUNK_3 << std::endl;

        const unsigned int ARRAY_OF_CHUNKS[3] = {CHUNK_1, CHUNK_2, CHUNK_3};
        unsigned int longestChunk = ARRAY_OF_CHUNKS[0];
        for (unsigned int i = 1; i < 3; i++) {
            const unsigned int currentChunk = ARRAY_OF_CHUNKS[i];
            if (currentChunk > longestChunk) {
                longestChunk = currentChunk; 
            }
        }
        // std::cout << longestChunk << std::endl;

        if (longestChunk == CHUNK_1) {
            if (CHUNK_1 < (CHUNK_2 + CHUNK_3)) {
                temp++;
            }
        } else if (longestChunk == CHUNK_2) {
            if (CHUNK_2 < (CHUNK_1 + CHUNK_3)) {
                temp++;
            }
        } else {
            if (CHUNK_3 < (CHUNK_1 + CHUNK_2)) {
                temp++;
            }
        }

        count++;
        std::cout << count << ".... " << std::endl;
    };

    // std::cout << temp << std::endl;

    return 0;
} 
