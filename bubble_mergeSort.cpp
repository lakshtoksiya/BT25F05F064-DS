#include <iostream>
using namespace std;

const int SIZE = 8;

// Bubble Sort
void bubbleSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge function
void merge(int arr[], int low, int mid, int high) {
    int temp[SIZE];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Display array
void display(int arr[]) {
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int arr[SIZE];
    int choice;

    cout << "Enter 8 elements:\n";

    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    cout << "\n----- SORTING MENU -----\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr);
            cout << "\nArray after Bubble Sort:\n";
            display(arr);
            break;

        case 2:
            mergeSort(arr, 0, SIZE - 1);
            cout << "\nArray after Merge Sort:\n";
            display(arr);
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
