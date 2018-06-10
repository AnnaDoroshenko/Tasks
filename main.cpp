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
    // std::vector<unsigned int> vect = {};

    findMinMax(vect, &min, max);

    if (vect.size() != 0) {
        std::cout << "min = " << min << std::endl;
        std::cout << "max = " << max << std::endl;
    }

    return 0;
}


void findMinMax(
        const std::vector<unsigned int>& array,
        unsigned int* min, unsigned int& max) {
    if (array.size() == 0) {
        std::cout << "Gimme numbers, clever one" << std::endl;
        return;
    }
    *min = array[0];
    max = array[0];
    for (unsigned int i = 1; i < array.size(); i++) {
        if (array[i] < *min) {
            *min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }
return;
}


// std::pair<unsigned int, unsigned int> findMinMax(const std::vector<unsigned int>& array) {
//     return {};
// }
