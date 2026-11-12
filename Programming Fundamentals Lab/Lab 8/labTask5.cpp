#include <iostream>
using namespace std;
void readArray(int arr[], int size);
int  countEven(const int arr[], int size);
void reverseArray(int arr[], int size);
void printArray(const int arr[], int size);
int main() {
    const int SIZE = 5;
    int arr[SIZE];
    readArray(arr, SIZE);
    cout << "Even numbers: " << countEven(arr, SIZE) << endl;
    reverseArray(arr, SIZE);
    cout << "Reversed: ";
    printArray(arr, SIZE);
    return 0;
}
void readArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }
}
int countEven(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}