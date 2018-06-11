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

    if (vect.size() != 0) {
        const std::pair<unsigned int, unsigned int> minMaxPair = findMinMax(vect).value();
        std::cout << "min = " << minMaxPair.first << std::endl;
        std::cout << "max = " << minMaxPair.second << std::endl;
    }
    //
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
        // FIXME: "boost" is a widely-known library for c++. Many things from there
        // end up in the C++ standart.
        // DO read more about std::optional and implement it here.
        // However, std::optional is a part of C++ standart as of c++17
        // (so no need to write "boost", just include the c++ library).
        // In order to enable it, add "-std=c++17" into your Makefile into
        // Compilation and Execution (after optimization flag).
        // If your linter (vim) complains about it, find out how to add this
        // compiler argument in your .vimrc for the linter.
        // Also, why is there no ";" at the end??
        return std::optional<std::pair< unsigned int, unsigned int>> ();
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
    std::pair<unsigned int, unsigned int> resultPair = std::make_pair(min, max);
    
    return std::optional<std::pair< unsigned int, unsigned int>> (resultPair);
}
