class Solution {
    public int minimumRecolors(String blocks, int k) {
        int count=0,n=blocks.length();
        for(int i=0;i<k;i++){
            if(blocks.charAt(i)=='W'){
                count++;
            }
        }
        int minc=count;
        for(int i=1;i<n-k+1;i++){
            if(blocks.charAt(i-1)=='W'){
                count--;
            }
            if(blocks.charAt(i+k-1)=='W'){
                count++;
            }
            minc=Math.min(minc,count);
        }
        return minc;
    }
}