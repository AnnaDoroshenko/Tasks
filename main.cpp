#include <iostream>
#include <vector>
#include <optional>


void findMinMax(
        const std::vector<unsigned int>& array,
        unsigned int* min, unsigned int& max);
std::optional<std::pair<unsigned int, unsigned int>> findMinMax(const std::vector<unsigned int>& array);


int main() {
    unsigned int min;
    unsigned int max;
    // const std::vector<unsigned int> vect = {3, 4, 7, 9, 2};
    const std::vector<unsigned int> vect = {};
    const std::optional<std::pair<unsigned int, unsigned int>> foundPair = findMinMax(vect);

    if (foundPair) {
        const std::pair<unsigned int, unsigned int> minMaxPair = foundPair.value();
        std::cout << "min = " << minMaxPair.first << std::endl;
        std::cout << "max = " << minMaxPair.second << std::endl;
    }

    // findMinMax(vect, &min, max);
    //
    // if (vect.size() != 0) {
    //     std::cout << "min = " << min << std::endl;
    //     std::cout << "max = " << max << std::endl;
    // }

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
}


std::optional<std::pair<unsigned int, unsigned int>> findMinMax(const std::vector<unsigned int>& array) {
    if (array.size() == 0) {
        std::cout << "Gimme numbers, clever one" << std::endl;

        // return std::optional<std::pair<unsigned int, unsigned int>> ();
        // return std::nullopt;
        return {};
    }

    unsigned int min = array[0];
    unsigned int max = array[0];
    for (unsigned int i = 1; i < array.size(); i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    // return std::optional<std::pair< unsigned int, unsigned int>> (std::make_pair(min, max));
    return std::make_pair(min, max);
}
