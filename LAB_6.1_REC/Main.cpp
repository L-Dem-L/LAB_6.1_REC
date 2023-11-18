#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 25;
const int LOWER_BOUND = 15;
const int UPPER_BOUND = 94;

void fillArray(int arr[], int index = 0) {
    if (index < ARRAY_SIZE) {
        arr[index] = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
        fillArray(arr, index + 1);
    }
}

void printArray(const int arr[], int index = 0) {
    if (index < ARRAY_SIZE) {
        std::cout << arr[index] << " ";
        printArray(arr, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

void processArrayRecursive(int arr[], int index, int& count, int& sum) {
    if (index < ARRAY_SIZE) {
        if (index % 2 != 0 && index % 13 != 0) {
            count++;
            sum += arr[index];
            arr[index] = 0;
        }
        processArrayRecursive(arr, index + 1, count, sum);
    }
}

void processArray(int arr[], int& count, int& sum) {
    count = 0;
    sum = 0;
    processArrayRecursive(arr, 0, count, sum);
}

int main() {
    std::srand(std::time(0));

    int myArray[ARRAY_SIZE];
    int count, sum;

    fillArray(myArray);
    std::cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;
    std::cout << "Modified Array: ";
    printArray(myArray);

    return 0;
}
