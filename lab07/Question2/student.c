#include <stdlib.h>
/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

void mergeSort(int arr[], int size) {

    if(size == 1) {
        return;
    }

    int** newArr = malloc(sizeof(int*) * size);
    int newSize = size;

    for(int i = 0; i < size; i++) {
        int* reArr = malloc(sizeof(int) * 2);
        reArr[0] = 1;
        reArr[1] = arr[i];
        newArr[i] = reArr;
    }

    while(newSize > 1) {
        for(int i = 0; i < newSize - 1; i++) {
            
            int curSz = newArr[i][0];
            int nextSz = newArr[i + 1][0];

            int* reArr = malloc(sizeof(int) * (curSz + nextSz + 1));
            reArr[0] = curSz + nextSz;

            int curI = 0;
            int nextI = 0;

            for(int j = 1; j < (curSz + nextSz) + 1; j++) {
                if(curI == curSz) {
                    reArr[j] = newArr[i+1][nextI + 1];
                    nextI++;
                    continue;
                } else if(nextI == nextSz) {
                    reArr[j] = newArr[i][curI + 1];
                    curI++;
                    continue;
                }
                if(newArr[i][curI + 1] <= newArr[i+1][nextI + 1]) {
                    reArr[j] = newArr[i][curI + 1];
                    curI++;
                } else {
                    reArr[j] = newArr[i+1][nextI + 1];
                    nextI++;
                }
            }

            newArr[i] = reArr;
            for(int j = i + 1; j < newSize - 1; j++) {
                newArr[j] = newArr[j + 1];
            }

            newSize--;

        }

    }

    int saveSz = newArr[0][0];

    for(int i = 0; i < size ; i++) {
        arr[i] = newArr[0][i + 1];
    }

    (void)arr;
    (void)size;
}

