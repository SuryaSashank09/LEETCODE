import java.util.HashSet;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        int si = 0;
        int currentSum = 0;
        int maxSum = 0;
        
        for (int li = 0; li < nums.length; li++) {
            while (set.contains(nums[li])) {
                set.remove(nums[si]);
                currentSum -= nums[si];
                si++;
            }
            
            set.add(nums[li]);
            currentSum += nums[li];
            
            maxSum = Math.max(maxSum, currentSum);
        }
        
        return maxSum;
    }
}