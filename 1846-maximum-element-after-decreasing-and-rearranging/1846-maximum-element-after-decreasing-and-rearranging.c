#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    int maxVal = 1; 
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] >= maxVal + 1) {
            maxVal++;
        }
    }
    return maxVal;
}
