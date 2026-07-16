class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length,i=0;
        while(i<n){
            int ci=nums[i];
            if(ci!=n && nums[i]!=nums[ci]){
                int temp=nums[ci];
                nums[ci]=nums[i];
                nums[i]=temp;
            }else{
                i++;
            }
        }
        for(i=0;i<n;i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return n;
    }
}