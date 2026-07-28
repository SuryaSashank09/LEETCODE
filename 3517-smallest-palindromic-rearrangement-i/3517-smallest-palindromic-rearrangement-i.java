import java.util.Arrays;

class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        int halfLen = n / 2;
        
        char[] half = s.substring(0, halfLen).toCharArray();
        Arrays.sort(half);
        
        String leftHalf = new String(half);
        String rightHalf = new StringBuilder(leftHalf).reverse().toString();
        
        if (n % 2 != 0) {
            return leftHalf + s.charAt(halfLen) + rightHalf;
        }
        
        return leftHalf + rightHalf;
    }
}