#include <iostream>
/* #include <stdlib.h> // for srand(), rand() */
/* #include <time.h> // for time() */


int main() {
    srand(time(0)); // for automatic random number generation
    const float LENGTH = 1.0;
    unsigned int count = 0;
    unsigned int temp = 0;
    const unsigned int PRESICION = 1000000;

    while (count < PRESICION) {
        float CHUNK_1;
        float CHUNK_2;
        float CHUNK_3;
        const float POINT_1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        const float POINT_2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

        if (POINT_1 > POINT_2) {
            CHUNK_1 = POINT_2;
            CHUNK_2 = POINT_1 - POINT_2;
            CHUNK_3 = LENGTH - POINT_1;
        } else {
            CHUNK_1 = POINT_1;
            CHUNK_2 = POINT_2 - POINT_1;
            CHUNK_3 = LENGTH - POINT_2;
        }

        const float ARRAY_OF_CHUNKS[3] = {CHUNK_1, CHUNK_2, CHUNK_3};
        float longestChunk = ARRAY_OF_CHUNKS[0];
        unsigned int indexOfTheLongestChunk = 0;
        for (unsigned int i = 1; i < 3; i++) {
            const unsigned int currentChunk = ARRAY_OF_CHUNKS[i];
            if (currentChunk > longestChunk) {
                longestChunk = currentChunk; 
                indexOfTheLongestChunk = i;
            }
        }

        switch (indexOfTheLongestChunk) {
            case 0:
                if (CHUNK_1 < (CHUNK_2 + CHUNK_3)) {
                    temp++;
                }
                break;
            case 1:
                if (CHUNK_2 < (CHUNK_1 + CHUNK_3)) {
                    temp++;
                }
                break;
            case 2:
                if (CHUNK_3 < (CHUNK_1 + CHUNK_2)) {
                    temp++;
                }
                break;
            default:
                break;
        }

        count++;
        /* std::cout << ".... " << std::endl; */
    };

    std::cout << (float) temp / PRESICION << std::endl;

    return 0;
} 
