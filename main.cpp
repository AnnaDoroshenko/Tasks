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

    if (vect.size() != 0) {
        // FIXME: OK, but better to use what std::optional offers you instead of
        // checking size() yourself. Do: if(foundPair) {...}
        const std::pair<unsigned int, unsigned int> minMaxPair = foundPair.value();
        std::cout << "min = " << minMaxPair.first << std::endl;
        std::cout << "max = " << minMaxPair.second << std::endl;
    }

    // FIXME: Remember the video about using IFs?
    // Do all your error-checking IFs first and continue the 'normal' flow on
    // the main level (thus avoiding nested IFs).
    // So do like:
    // if (!foundPair) {
    //  // report
    // }
    // // print minMax

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

        // FIXME: we've agreed that this one is probably equal to {} or std::nullopt.
        // Use one of those two.
        // return std::optional<std::pair<unsigned int, unsigned int>> ();
        return std::nullopt;
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

    // std::pair<unsigned int, unsigned int> resultPair = std::make_pair(min, max);
    // return std::optional<std::pair< unsigned int, unsigned int>> (resultPair);
    // FIXME: better do just:
    // return std::optional<std::pair< unsigned int, unsigned int>> (std::make_pair(min, max));
    // FIXME: Or even better (use the fact that this thing will be implicitly
    // converted into optional (helps readability).
    return std::make_pair(min, max);
}
