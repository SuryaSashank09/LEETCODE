class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int initialOnes = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                initialOnes++;
            }
        }

        String t = "1" + s + "1";
        int maxGain = 0;
        int prevZeroLen = 0;
        int currZeroLen = 0;
        boolean inOnesBlock = false;

        int i = 0;
        while (i < t.length()) {
            if (t.charAt(i) == '0') {
                int start = i;
                while (i < t.length() && t.charAt(i) == '0') {
                    i++;
                }
                int len = i - start;
                if (inOnesBlock) {
                    maxGain = Math.max(maxGain, prevZeroLen + len);
                }
                prevZeroLen = len;
                inOnesBlock = false;
            } else {
                int start = i;
                while (i < t.length() && t.charAt(i) == '1') {
                    i++;
                }
                if (prevZeroLen > 0) {
                    inOnesBlock = true;
                }
            }
        }

        return initialOnes + maxGain;
    }
}