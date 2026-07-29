class Solution {
    public String smallestPalindrome(String s, int k) {
        int n = s.length();
        int halfLen = n / 2;
        int[] freq = new int[26];
        
        for (int i = 0; i < n; i++) {
            freq[s.charAt(i) - 'a']++;
        }
        
        char midChar = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                midChar = (char) ('a' + i);
            }
            freq[i] /= 2;
        }

        long cap = k + 1L;
        if (countPermutations(freq, halfLen, cap) < k) {
            return "";
        }

        StringBuilder half = new StringBuilder();
        for (int i = 0; i < halfLen; i++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0) continue;
                
                freq[c]--;
                long ways = countPermutations(freq, halfLen - 1 - i, cap);
                
                if (ways >= k) {
                    half.append((char) ('a' + c));
                    break;
                } else {
                    k -= ways;
                    freq[c]++;
                }
            }
        }

        StringBuilder result = new StringBuilder(half);
        if (n % 2 != 0) {
            result.append(midChar);
        }
        result.append(new StringBuilder(half).reverse());

        return result.toString();
    }

    private long countPermutations(int[] freq, int totalLen, long cap) {
        long ways = 1;
        int rem = totalLen;
        for (int f : freq) {
            if (f == 0) continue;
            long comb = combinations(rem, f, cap);
            ways = multiplyCap(ways, comb, cap);
            if (ways >= cap) return cap;
            rem -= f;
        }
        return ways;
    }

    private long combinations(int n, int r, long cap) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - i + 1) / i;
            if (res >= cap) return cap;
        }
        return res;
    }

    private long multiplyCap(long a, long b, long cap) {
        if (a == 0 || b == 0) return 0;
        if (a >= cap || b >= cap) return cap;
        if (a > cap / b) return cap;
        return Math.min(a * b, cap);
    }
}