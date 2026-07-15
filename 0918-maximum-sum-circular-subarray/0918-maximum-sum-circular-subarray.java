class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int sum1 = nums[0], sum2 = nums[0], maxsum = nums[0], minsum = Integer.MAX_VALUE, totalsum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum1 = Math.max(sum1 + nums[i], nums[i]);
            maxsum = Math.max(maxsum, sum1);
            sum2 = Math.min(sum2 + nums[i], nums[i]);
            minsum = Math.min(minsum, sum2);
            totalsum += nums[i];
        }
        if (maxsum < 0) {
            return maxsum;
        }
        return Math.max(maxsum, totalsum - minsum);
    }
}