class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        int T = 0, F = 0;
        int countF = 0, countT = 0;
        int maxLen = 0;

        for (int right = 0; right < answerKey.length(); right++) {
            char rightChar = answerKey.charAt(right);
            
            if (rightChar == 'F') countF++;
            while (countF > k) {
                if (answerKey.charAt(T) == 'F') countF--;
                T++;
            }
            
            if (rightChar == 'T') countT++;
            while (countT > k) {
                if (answerKey.charAt(F) == 'T') countT--;
                F++;
            }
            maxLen = Math.max(maxLen, right - T + 1);
            maxLen = Math.max(maxLen, right - F + 1);
        }

        return maxLen;
    }
}