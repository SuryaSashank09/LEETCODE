class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n=nums.length,i=0,ci,temp;
        while(i<n){
            ci=nums[i]-1;
            if(nums[i]!=nums[ci]){
                temp=nums[i];
                nums[i]=nums[ci];
                nums[ci]=temp;
            }else{
                i++;
            }
        }
        ArrayList<Integer> l = new ArrayList<>();
        for(i=0;i<n;i++){
            if(i!=nums[i]-1){
                l.add(i+1);
        }
    }
    return l;
    }
}