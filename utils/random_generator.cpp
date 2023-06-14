#include "random_generator.h"

std::vector<int> random_gen(int n, int min, int max) {
    srand(time(nullptr));

    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(rand() % (max - min + 1) + min);
    }
    return result;
}