#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    int* i = nums;
    int* j = nums + ((n - 1) * sizeof(int));

    while(*i + *j != target) {
        if(*i + *j < target) {
            i += sizeof(int);
        } else {
            j -= sizeof(int);
        }
        if(j < i) {
            return 0;
        }
    }

    *out_i = i;
    *out_j = j;
    return 1;
}
// think about the time complexity and space complexity of your solution

