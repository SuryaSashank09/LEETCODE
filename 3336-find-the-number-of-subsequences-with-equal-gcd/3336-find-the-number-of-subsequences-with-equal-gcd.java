import java.util.Arrays;

class Solution {
    public int subsequencePairCount(int[] nums) {
        final int MOD = 1_000_000_007;
        int maxVal = 200;
        long[][] dp = new long[maxVal + 1][maxVal + 1];
        dp[0][0] = 1;

        for (int num : nums) {
            long[][] ndp = new long[maxVal + 1][maxVal + 1];
            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    long val = dp[g1][g2];
                    if (val == 0) continue;

                    ndp[g1][g2] = (ndp[g1][g2] + val) % MOD;

                    int ng1 = (g1 == 0) ? num : gcd(g1, num);
                    ndp[ng1][g2] = (ndp[ng1][g2] + val) % MOD;

                    int ng2 = (g2 == 0) ? num : gcd(g2, num);
                    ndp[g1][ng2] = (ndp[g1][ng2] + val) % MOD;
                }
            }
            dp = ndp;
        }

        long ans = 0;
        for (int g = 1; g <= maxVal; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }
        return (int) ans;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}