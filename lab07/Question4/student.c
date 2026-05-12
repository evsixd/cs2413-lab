/*
Question 4: Insertion Sort

Description:
Implement insertion sort for an integer array.

Insertion sort builds the sorted portion of the array one element at a time.
For each element, it inserts that element into the correct position among
the elements before it.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- Do not use any built-in sorting function.
*/

void insertionSort(int arr[], int size) {

    int sorted = 1;
    // initiate base case for loop

    while(sorted < size) {
        int ind = size - 1;
        while(arr[0] <= arr[ind]) {
            ind--;
            if(ind == size - sorted - 1) {
                break;
            }
        }
        int reStow = arr[0];
        for(int i = 0; i < ind; i++) {
            arr[i] = arr[i+1];
        }
        arr[ind] = stow;
        sorted++;
    }

    (void)arr;
    (void)size;
}
