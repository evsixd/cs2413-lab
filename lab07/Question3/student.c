#include <stdlib.h>
/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/

void quickSort(int arr[], int size) {

    int** reArr = malloc(sizeof(int*) * size);
    int reSize = 1;

    int* arrClone = malloc(sizeof(int) * (size + 1));
    arrClone[0] = size;

    for(int i = 0; i < size; i++) {
        arrClone[i + 1] = arr[i];
    }

    reArr[0] = arrClone;

    // copied initial array into reArr[0], 0th index the size

    while(reSize < size) {
        int initSize = reSize;
        for(int i = 0; i < initSize; i++) {
            int subSize = reArr[i][0];
            if(subSize == 1) {
                continue;
            }
            int lowest = 1;
            for(int j = 2; j < subSize + 1; j++) {
                if(reArr[i][j] > reArr[i][lowest]) { // here repeatedly locates the highest element, and then places it outside of the primary array (the pivot)
                    lowest = j;
                }
            }
            int stow = reArr[i][lowest];
            arr[size - reSize] = stow;
            reArr[i][lowest] = reArr[i][subSize];
            reArr[i][0] = reArr[i][0] - 1;

            int* crayArray = malloc(sizeof(int) * 2);
            crayArray[0] = 1;
            crayArray[1] = stow;

            reSize++; 

            for(int j = reSize; j > i; j--) {
                reArr[j] = reArr[j - 1];
            }
            reArr[i + 1] = crayArray;

        }
    }

    arr[0] = reArr[0][1];

    (void)arr;
    (void)size;
}

