#include <iostream>
#include "random_generator.cpp"
#include "sorting.cpp"

using namespace std;

int main() {
    auto array = random_gen(20, 0, 100);

    for (auto i: array) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(array, 0, array.size() - 1);

    for (auto i: array) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}