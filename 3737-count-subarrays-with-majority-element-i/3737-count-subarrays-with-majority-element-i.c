int countMajoritySubarrays(int* nums, int numsSize, int target) {
    int result = 0;
    int* prefix = (int*)malloc((numsSize + 1) * sizeof(int));
    prefix[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : 0);
    }

    for (int start = 0; start < numsSize; start++) {
        for (int end = start; end < numsSize; end++) {
            int length = end - start + 1;
            int countTarget = prefix[end + 1] - prefix[start];
            if (countTarget * 2 > length) {
                result++;
            }
        }
    }

    free(prefix);
    return result;
}
