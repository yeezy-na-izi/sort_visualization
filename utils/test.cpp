#include <iostream>
#include "random_generator.h"


void quick_sort(std::vector<int> &array, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    quick_sort(array, left, j);
    quick_sort(array, i, right);
}


int main() {
    std::vector<int> array = random_gen(10, 0, 100);
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    quick_sort(array, 0, array.size() - 1);
    for (int i : array) {
        std::cout << i << " ";
    }
    return 0;
}