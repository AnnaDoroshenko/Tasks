#include <cassert>
#include <iostream>

float pyramid(int row, int column) {
    if (row == 0) return 1;
    else if (column == 0) return 1+pyramid(row-1, column)/2;
    else if (column == row) return 1+pyramid(row-1, column-1)/2;
    else return 1+(pyramid(row-1, column-1)+pyramid(row-1, column))/2;
}

int main() {
    assert(pyramid(0,0) == 1.0f);
    assert(pyramid(1,0) == 1.5f);
    assert(pyramid(1,1) == 1.5f);
    assert(pyramid(3,1) == 25.0f/8.0f);
    assert(pyramid(3,3) == 15.0f/8.0f);
    return 0;
}
