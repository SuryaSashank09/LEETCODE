import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int si = 0;
        int maxLength = 0;
        for (int li = 0; li < s.length(); li++) {
            char currentChar = s.charAt(li);
            while (set.contains(currentChar)) {
                set.remove(s.charAt(si));
                si++;
            }
            set.add(currentChar);
            maxLength = Math.max(maxLength, li - si + 1);
        }
        return maxLength;
    }
}