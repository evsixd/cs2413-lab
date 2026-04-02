/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

#include <stdlib.h>
#include <stdio.h>

/*
Optional helper structure for a hash table entry.

You may use this structure if you want to build your own hash table.
key   -> the number from the array
value -> the index of that number
*/
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/*
Optional table size for a simple hash table implementation.
You may change this value if needed.
*/
#define TABLE_SIZE 100

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static int hash(int key);
static void insert(Node** table, int key, int value);
static int find(Node** table, int key);

/*
Return an array of size 2 containing the indices of the two numbers
whose sum equals target.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;

    Node** table = malloc(sizeof(Node) * TABLE_SIZE);

    for(int i = 0; i < numsSize; i++) {
        int verify = find(table, target - nums[i]);
        if(verify != -1) {
            *returnSize = 2;

            int* returning = malloc(sizeof(int) *2);
            returning[0] = table[verify]->value;
            returning[1] = i;

            return returning;
        }
        insert(table, nums[i], i);
    }

    free(table);
    return NULL;
}


static int hash(int key) {
    float a = 0.736123;
    float rekey = a * key;
    int subkey = (int) rekey;

    rekey -= subkey;

    rekey *= TABLE_SIZE;
    int finalize = (int) rekey;

    if(finalize < 0) {
        finalize *= -1;
    }
    return finalize;
}


static void insert(Node** table, int key, int value) {
    int hashed = hash(key);
    int rehash = hashed;

    while(1) {
        if(table[rehash] == NULL) {
            table[rehash] = malloc(sizeof(Node));
            table[rehash]->key = key;
            table[rehash]->value = value;
            return;
        }

        rehash += 1;
        rehash %= TABLE_SIZE;
        if(rehash == hashed) {
            return;
        }
    }
}


static int find(Node** table, int key) {
    int hashed = hash(key);
    int rehash = hashed;

    while(1) {
        if(table[rehash] != NULL && table[rehash]->key == key) {
            return rehash;
        }
        rehash += 1;
        rehash %= TABLE_SIZE;
        if(rehash == hashed) {
            return -1;
        }
    }
    return -1; // return -1 if not found, otherwise return depth
}

/*
Optional helper: free all memory used by the hash table.
*/