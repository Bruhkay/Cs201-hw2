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

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // number found at i
        }
    }
    return -1;  //number not found
}

int recursiveLinearSearch(int arr[], int size, int target, int index = 0) {
    if (index == size) {
        return -1;  //Base case: numebr not found
    }
    if (arr[index] == target) {
        return index;  // number found at index
    }
    return recursiveLinearSearch(arr, size, target, index + 1);  // Recursive call to check next element
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // number found at mid
        }
        if (arr[mid] < target) { //dividing into two
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  //number not found
}

int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);  // Block size to be jumped
    int prev = 0;

    // Jump forward in blocks until the element at the step exceeds the target or we reach the end
    while (arr[min(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; //number not found
        }
    }

    // Perform linear search in the block starting from `prev` to `step`
    for (int i = prev; i < min(step, size); i++) {
        if (arr[i] == target) {
            return i;  // Target found at index i
        }
    }

    return -1;  //number not found
}

int randomSearch(int array[], int size, int target) {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generator

    // Dynamically allocate an array to keep track of visited indices
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
        visited[i] = false;  // Initialize all values to false
    }

    int attempts = 0;
    while (attempts < size) {
        // Generate a random index that hasn't been visited yet
        int randomIndex;
        do {
            randomIndex = rand() % size;  // Get a random index within bounds
        } while (visited[randomIndex]);  // Ensure the index hasn't been visited

        // Mark this index as visited
        visited[randomIndex] = true;
        attempts++;

        // Check if the value at the random index is the target
        if (array[randomIndex] == target) {
            delete[] visited;  // Don't forget to free the allocated memory
            return randomIndex;  // Return the index of the target
        }
    }

    delete[] visited;  // Free the allocated memory if target is not found
    return -1;  // If we exhaust all elements without finding the target
}

int main()
{
    //cout<<"Non-Recursive Linear Search: d"<< endl;
    //cout<<"Recursive Linear Search: d"<< endl;
    //cout<<"Binary Search: d"<< endl;
    //cout<<"Jump Search: d"<< endl;
    cout<<"Random Search: a"<< endl;
    for(int i = 1; i <= 8; i++) {


        int maxValue = pow(10,i+1);
        int size = pow(10,i);
        int* array = new int[size];
        generateSortedRandomArray(array, size, maxValue); // generates a sorted random array

        int manytimes = pow(10,(11-i)/2);
        int a = array[size/6];
        //int b = array[size/2];
        //int c = array[(5*size)/6];
        //int d = -1;
        int k = 0;

        //Store the starting time
        double duration;
        clock_t startTime = clock();

        for(int j = 0; j < manytimes; j++) {
            k = randomSearch(array, size, a);
        }

        duration = 1000 * double( clock() - startTime ) / (CLOCKS_PER_SEC*manytimes);
        cout << "Execution took " << duration << " milliseconds. For 10^"<<i << " Target= "<< a << " find at= " << k << endl;


        delete[] array;
    }

    return 0;
}
