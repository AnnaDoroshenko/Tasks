#include <iostream>
#include <vector>


void findMinMax(
        const std::vector<unsigned int>& array,
        unsigned int* min, unsigned int& max);
std::pair<unsigned int, unsigned int> findMinMax(const std::vector<unsigned int>& array);


int main() {
    unsigned int min;
    unsigned int max;
    // const std::vector<unsigned int> vect = {3, 4, 7, 9, 2};
    const std::vector<unsigned int> vect = {};
    // const std::pair<unsigned int, unsigned int> minMaxpair;

    if (vect.size() != 0) {
        // FIXME: you make your code evaluate the func findMinMax() twice (expensive!).
        // Call once, store result, access .first and .second from the stored result.
        std::cout << "min = " << findMinMax(vect).first << std::endl;
        std::cout << "max = " << findMinMax(vect).second << std::endl;
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


std::pair<unsigned int, unsigned int> findMinMax(const std::vector<unsigned int>& array) {
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
        return // boost::optional<std::pair<unsigned int, unsigned int> > ();
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
    
    // FIXME: Good, but for simplicity use just {min, max}.
    // The compiler understands the type of {min, max} because it knows the
    // functiuon return type.
    return std::make_pair(min, max);
}

