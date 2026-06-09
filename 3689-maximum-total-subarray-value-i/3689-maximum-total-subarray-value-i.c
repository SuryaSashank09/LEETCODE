long long maxTotalValue(int* nums, int numsSize, int k) {
    int maxVal = nums[0], minVal = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > maxVal) maxVal = nums[i];
        if (nums[i] < minVal) minVal = nums[i];
    }
    
    long long bestValue = (long long)(maxVal - minVal);
    
    return bestValue * k;
}
