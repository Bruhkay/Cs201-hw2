#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void generateSortedRandomArray(int* array, int size, int maxValue) {
    srand(std::time(nullptr));

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % (maxValue+ 1);
    }

    sort(array, array + size);
}
int main()
{
    int maxValue = 100;
    int size = 100;
    int* array = new int[size];

    generateSortedRandomArray(array, size, maxValue);
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }

    delete[] array;
    return 0;
}
