class Solution {
    public int maxProduct(int[] nums) {
        int mp=0;
        for(int i=0;i<nums.length;i++){
           for(int j=i+1;j<nums.length;j++){
            int p=(nums[i]-1)*(nums[j]-1);
            if(p>mp){
                mp=p;
            }
           }
    }
    return mp;
}
}