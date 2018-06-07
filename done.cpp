#include <iostream>


void Task1() {
    const unsigned int HEIGHT = 5;
    char stairs[HEIGHT][HEIGHT];

    for (unsigned int i = 0; i < HEIGHT; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            stairs[i][j] = (j < i) ? ' ' : (((i + j) % 2 == 0) ? '0' : '1');
        }
    }

    for (unsigned int i = HEIGHT; i > 0; i--) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            stairs[i-1][j] = (j < HEIGHT-i) ? ' ' : '1';
        }
    }

    // For transposition of the matrix
    for (unsigned int i = 0; i<HEIGHT/2; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
           char buff = stairs[i][j];
           stairs[i][j] = stairs[HEIGHT-1-i][j];
           stairs[HEIGHT-1-i][j] = buff;
        }
    }

    for (unsigned int i = 0; i < HEIGHT; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            std::cout << stairs[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
