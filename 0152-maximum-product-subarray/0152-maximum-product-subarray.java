class Solution {
    public int maxProduct(int[] nums) {
        int p1 = nums[0];
        int p2 = nums[0];
        int maxproduct = nums[0];
        int temp;
        for (int i = 1; i < nums.length; i++) {
            temp = p1;

            p1 = Math.max(nums[i], Math.max(p1 * nums[i], p2 * nums[i]));
            p2 = Math.min(nums[i], Math.min(p2 * nums[i], temp * nums[i]));

            maxproduct = Math.max(maxproduct, p1);
        }
        return maxproduct;
    }

}