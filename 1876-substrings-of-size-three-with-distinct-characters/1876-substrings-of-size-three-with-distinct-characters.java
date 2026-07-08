class Solution {
    public int countGoodSubstrings(String s) {
        int count = 0,k=3;
        int n = s.length();
        for (int i = 0; i <= n-k; i++) {
            char a = s.charAt(i);
            char b = s.charAt(i + 1);
            char c = s.charAt(i + 2);
            if (a != b && b != c && a != c) {
                count++;
            }
        }
        
        return count;
    }
}