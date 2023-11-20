#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void fillArray(int arr[], int index = 0) {
    if (index < 25) {
        arr[index] = rand() % (94 - 15 + 1) + 15;
        fillArray(arr, index + 1);
    }
}

void printArray(const int arr[], int index = 0) {
    if (index < 25) {
        std::cout << std::setw(4) << arr[index];
        printArray(arr, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

void processArrayRecursive(int arr[], int index, int& count, int& sum) {
    if (index < 25) {
        if (!(arr[index] % 2 == 0 && index % 13 == 0)) {
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

    int myArray[25];
    int count, sum;

    fillArray(myArray);
    std::cout << "Original Array: ";
    printArray(myArray);

    processArray(myArray, count, sum);
    std::cout << "Modified Array: ";
    printArray(myArray);
    std::cout << "Count of elements satisfying the criteria: " << count << std::endl;
    std::cout << "Sum of elements satisfying the criteria: " << sum << std::endl;

    return 0;
}
