#include "Student.h"
#include <stdlib.h>

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
    // TODO: implement
    int* uniques = malloc(sizeof(int) * numsSize);
    int u_i = 0;
    for(int i = 0; i < numsSize; i++) {
        int duplicate = 0;
        for(int j = 0; j < u_i; j++) {
            if(uniques[j] == nums[i]) {
                duplicate = 1;
                continue; // check if uniques list has registered the digits index
            }
        }
        if(!duplicate) {
            uniques[u_i] = nums[i];
            u_i++; // if not a duplicate, append to duplicate
            // then... scan for quantity of this unique num
            int quantity = 0;
            for(int j = 0; j < numsSize; j++) {
                if(nums[j] == nums[i]) {
                    quantity++;
                }
            }
            if(quantity > numsSize / 2) {
               free(uniques);
               return nums[i];
            }
        } 
        //
    }

    free(uniques);
    return 0;
}
