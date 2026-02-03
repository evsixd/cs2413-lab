#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0 && i < j && j < k) {
                    *out_i = i;
                    *out_j = j;
                    *out_k = k;
                    return 1;
                }
            }
        }
    }

    return 0;
}
