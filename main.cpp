#include <iostream>
#include <vector>


void findMinMax(
        const std::vector<unsigned int>& array,
        unsigned int* min, unsigned int& max);
// std::pair<unsigned int, unsigned int> findMinMax(const std::vector<unsigned int>& array);


int main() {
    unsigned int min;
    unsigned int max;
    std::vector<unsigned int> vect = {3, 4, 7, 9, 2};

    // FIXME: WIll fail for empty vector. Think about how to remedy that
    findMinMax(vect, &min, max);

    std::cout << "min = " << min << std::endl;
    std::cout << "max = " << max << std::endl;


    return 0;
}


void findMinMax(
        const std::vector<unsigned int>& array,
        unsigned int* min, unsigned int& max) {
    *min = array[0];
    max = array[0];
    for (unsigned int i = 1; i < array.size(); i++) {
        // FIXME: no real readability benefits from making a separate variable
        // (but if you DO make it, make it const!)
        unsigned int currentInt = *min;
        if(array[i] < currentInt) {
            *min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
}


// std::pair<unsigned int, unsigned int> findMinMax(const std::vector<unsigned int>& array) {
//     return {};
// }
