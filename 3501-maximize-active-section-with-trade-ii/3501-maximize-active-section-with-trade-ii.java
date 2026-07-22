import java.util.*;

class Solution {
    public List<Integer> maxActiveSectionsAfterTrade(String s, int[][] queries) {
        int n = s.length();
        int[] prefOnes = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefOnes[i + 1] = prefOnes[i] + (s.charAt(i) == '1' ? 1 : 0);
        }

        List<int[]> segs = new ArrayList<>();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                j++;
            }
            segs.add(new int[]{s.charAt(i) - '0', j - i, i, j - 1});
            i = j;
        }

        int m = segs.size();
        int[] segIdx = new int[n];
        for (int k = 0; k < m; k++) {
            for (int idx = segs.get(k)[2]; idx <= segs.get(k)[3]; idx++) {
                segIdx[idx] = k;
            }
        }

        int[] val = new int[m];
        for (int k = 0; k < m; k++) {
            if (segs.get(k)[0] == 1) {
                int leftZeros = (k > 0 && segs.get(k - 1)[0] == 0) ? segs.get(k - 1)[1] : 0;
                int rightZeros = (k + 1 < m && segs.get(k + 1)[0] == 0) ? segs.get(k + 1)[1] : 0;
                val[k] = leftZeros + rightZeros;
            }
        }

        SegmentTree st = new SegmentTree(m, val);
        List<Integer> ans = new ArrayList<>(queries.length);

        int totalOnes = prefOnes[n];

        for (int[] q : queries) {
            int l = q[0], r = q[1];
            int sl = segIdx[l];
            int sr = segIdx[r];

            int maxGain = 0;

            int innerL = sl + 2;
            int innerR = sr - 2;
            if (innerL <= innerR) {
                maxGain = Math.max(maxGain, st.query(1, 0, m - 1, innerL, innerR));
            }

            for (int k = sl; k <= Math.min(sr, sl + 1); k++) {
                maxGain = Math.max(maxGain, getGain(k, l, r, segs, m));
            }
            for (int k = Math.max(sl, sr - 1); k <= sr; k++) {
                maxGain = Math.max(maxGain, getGain(k, l, r, segs, m));
            }

            ans.add(totalOnes + maxGain);
        }

        return ans;
    }

    private int getGain(int k, int l, int r, List<int[]> segs, int m) {
        if (k < 0 || k >= m || segs.get(k)[0] != 1) return 0;
        if (k - 1 < 0 || segs.get(k - 1)[0] != 0) return 0;
        if (k + 1 >= m || segs.get(k + 1)[0] != 0) return 0;

        int lLen = Math.max(0, Math.min(segs.get(k - 1)[3], r) - Math.max(segs.get(k - 1)[2], l) + 1);
        int rLen = Math.max(0, Math.min(segs.get(k + 1)[3], r) - Math.max(segs.get(k + 1)[2], l) + 1);

        if (lLen == 0 || rLen == 0) return 0; 
        
        return lLen + rLen;
    }

    static class SegmentTree {
        int n;
        int[] tree;

        public SegmentTree(int n, int[] arr) {
            this.n = n;
            tree = new int[4 * Math.max(1, n)];
            if (n > 0) build(1, 0, n - 1, arr);
        }

        private void build(int node, int start, int end, int[] arr) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = start + (end - start) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = Math.max(tree[2 * node], tree[2 * node + 1]);
        }

        public int query(int node, int start, int end, int l, int r) {
            if (l > end || r < start || l > r) return 0;
            if (l <= start && end <= r) return tree[node];
            int mid = start + (end - start) / 2;
            return Math.max(query(2 * node, start, mid, l, r),
                            query(2 * node + 1, mid + 1, end, l, r));
        }
    }
}
