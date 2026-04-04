/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* heap, int a, int b);
//static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = malloc(sizeof(int) * k);
    for(int i = 0; i < numsSize; i++) {
        if(i >= k) {
            for(int j = 0; j < k; j++) {
                if(heap[j] < nums[i]) {
                    heap[j] = nums[i];
                    heapifyDown(heap, k, 0);
                    break;
                }
            }
        } else {
            heap[i] = nums[i];
            heapifyDown(heap, i, 0);
        }
    }
    for(int i = 0; i < k; i++) {
        heapifyDown(heap, k, 0);
    }
    return heap[0];
}

/*
Optional helper: swap two integers.
*/
static void swap(int* heap, int a, int b) {
    int stow = heap[a];
    heap[a] = heap[b];
    heap[b] = stow;
    return;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
/*static void heapifyUp(int* heap, int index) {
    int sum = 1;
    int depthify = 1;
    while(sum <= index) {
        depthify*=2;
        sum+=depthify; // sum adds powers of 2 until equal with depth of index
        // depthify represents num of elements at depth of index
    }

    float mult = 0;
    if(depthify - 1 != 0) {
        mult = (index - (sum - depthify)) / (float) (depthify); // mult is the percentage of the way through the depth of index
    }

    int core = index - (index - sum + depthify + 1) + depthify + (mult * depthify * 2);
    int left = core + 1;    
    int right = left + 1;
}*/

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    int sum = 1;
    int depthify = 1;
    while(sum <= index) {
        depthify*=2;
        sum+=depthify; // sum adds powers of 2 until equal with depth of index
        // depthify represents num of elements at depth of index
    }

    float mult = 0;
    if(depthify - 1 != 0) {
        mult = (index - (sum - depthify)) / (float) (depthify); // mult is the percentage of the way through the depth of index
    }

    int core = index - (index - sum + depthify + 1) + depthify + (mult * depthify * 2);
    int left = core + 1;    
    int right = left + 1;

    //printf("\n%i %f | %i & %i | %i / %i -> L: %i R: %i\n", index, mult, sum, depthify, index - (sum - depthify), depthify - 1, left, right);

    if(left > size - 1) { // if left isn't in heap, abandon heapify
        return;
    } else if(right > size - 1) { // if right isn't in heap but left is, only look at left
        if(heap[left] < heap[index]) {
            swap(heap, left, index);
            heapifyDown(heap, size, left);
        }
    } else { // if both are in heap, analyze both
        if(heap[left] < heap[index] || heap[right] < heap[index]) {
            if(heap[left] < heap[right]) {
                swap(heap, left, index);
            } else {
                swap(heap, right, index);
            }
        }
        heapifyDown(heap, size, left);
        heapifyDown(heap, size, right);
    }
}