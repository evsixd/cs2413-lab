/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

void selectionSort(int arr[], int size) {
    int sorted = 0;
    while(sorted < size) {
        int highest = 0;
        for(int i = 1; i < size - sorted; i++) {
            if(arr[i] > arr[highest]) {
                highest = i;
            }
        }
        int stow = arr[highest];
        arr[highest] = arr[size - sorted - 1];
        arr[size - sorted - 1] = stow;

        sorted++;
    }
    (void)arr;
    (void)size;
}

