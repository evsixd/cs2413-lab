#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {

    for(int* i = nums; i < nums + (n * sizeof(int)); i += sizeof(int)) {
        for(int *j = i; j < nums + (n * sizeof(int)); j += sizeof(int)) {
            if(*i + *j == target) {
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }

    return 0;
}

//think about the time complexity and space complexity of your solution
