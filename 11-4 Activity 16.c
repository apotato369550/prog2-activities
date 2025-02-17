// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>

void selectionSort(int array[], int count);
void bubbleSort(int array[], int count);
void insertionSort(int array[], int count);

int main() {
    // Write C code here
    int array[] = {7, 0, 3, 1, 53, 12, 4, 17};
    int count = 8;
    
    // pick which sorting algorithm
    // selectionSort(array, 8);
    // bubbleSort(array, count);
    // insertionSort(array, count);
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void selectionSort(int array[], int count) {
    int min = INT_MAX;
    int least = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count; j++) {
            if (array[j] <= array[least]) {
                least = j;
            }
        }
        int temp = array[i];
        array[i] = array[least];
        array[least] = temp;
    }
}

void bubbleSort(int array[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            // printf("Comparing indexes: %d and %d \n", j, j + 1);
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int array[], int count) {
    for (int i = 1; i < count; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        
        array[j + 1] = key;
    }
}
