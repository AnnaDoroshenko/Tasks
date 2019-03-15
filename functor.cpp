#include <vector>
#include <cassert>


struct Match {
    Match(int i) : i(i) {}

    bool operator()(int x) const {
        return i == x;
    }

    const int i;
};

int find(const std::vector<int>& v, const Match& match) {
    for (int i : v) {
        if (match.operator()(i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<int> vect = {1,2,3,4,5};
    assert(find(vect, Match(4)) == 4);
    assert(find(vect, Match(6)) == -1);
    assert(find(vect, Match(3)) == -1);
}
