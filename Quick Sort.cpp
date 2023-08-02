#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int s = *a;
    *a = *b;
    *b = s;
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int partition(int array[], int p, int r) {
    int pivot = array[r];
    int i = (p - 1);
    for (int j = p; j < r; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    printArray(array, 8);
    cout << ".........\n";
    swap(&array[i + 1], &array[r]);
    return (i + 1);
}

void quickSort(int array[], int p, int r) {
    if (p < r) {
        int pi = partition(array, p, r);
        quickSort(array, p, pi - 1);
        quickSort(array, pi + 1, r);
    }
}

int main() {
    int data[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    cout << "\nSorted array in ascending order: \n";
    printArray(data, n);
}
