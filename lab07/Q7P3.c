#include <stdlib.h>
#include <stdio.h>

typedef struct TArray {
    int size;
    int* arr;
} TArray;

void TAppend(TArray* in, int val) {
    in->size = in->size + 1;
    in->arr = realloc(in->arr, sizeof(int) * in->size);
    in->arr[in->size - 1] = val;
}

TArray* TNew() {
    TArray* returning = malloc(sizeof(TArray));
    returning->size = 0;
    returning->arr = malloc(0);

    return returning;
}

void insertionSort(int arr[], int size) { // from my question 5
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
        arr[ind] = reStow;
        sorted++;
    }
}


// misc functions n stuffs done

void main() {
    int input[] = {39, 9, 81, 45, 90, 27, 72, 18}; // INPUT ARRAY HERE
    int k = 3; // INPUT K VALUE HERE

    int size = sizeof(input) / sizeof(int);


    TArray** subs = malloc(sizeof(TArray*) * size);
    int subsNum = 0;

    int n = 0;
    while(n < size) {
        TArray* stackify = TNew();
        for(int i = 0; i < k; i++) {
            if(i + n < size) {
                TAppend(stackify, input[i + n]);
            }
        }
        n += k;
        subs[subsNum] = stackify;
        subsNum++;
    }

    for(int i = 0; i < subsNum; i++) {
        insertionSort(subs[i]->arr, subs[i]->size);
    }

    while(subsNum > 1) {
        for(int i = 0; i < subsNum - 1; i++) {
            TArray* remake = TNew();
            int l = 0;
            int u = 0;

            for(int j = 0; j < subs[i]->size + subs[i+1]->size; j++) {
                if(l == subs[i]->size && u == subs[i+1]->size) {
                    break;
                }
                if(l == subs[i]->size) {
                    TAppend(remake, subs[i+1]->arr[u]);
                    u++;
                    continue;
                }
                if(u == subs[i+1]->size) {
                    TAppend(remake, subs[i]->arr[l]);
                    l++;
                    continue;
                }
                if(subs[i]->arr[l] < subs[i+1]->arr[u]) {
                    TAppend(remake, subs[i]->arr[l]);
                    l++;
                } else {
                    TAppend(remake, subs[i+1]->arr[u]);
                    u++;
                }
            }
            subs[i] = remake;
            for(int j = i + 1; j < subsNum - 1; j++) {
                subs[j] = subs[j+1];
            }
            subsNum--;
        }
    }

    TArray *final = subs[0];
    printf("\n\n{");
    for(int i = 0; i < final->size; i++) {
        printf("%i ", final->arr[i]);
    }
    printf("}\n\n");

}
