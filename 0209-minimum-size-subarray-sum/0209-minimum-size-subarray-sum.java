class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int si=0,minlen=nums.length+1,sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            while(sum>=target){
                int len = i-si+1;
                minlen = Math.min(minlen,len);
                sum-=nums[si];
                si++;
            }
        }
        if(minlen==nums.length+1){
                minlen=0;
            }
        return minlen;
    }
}