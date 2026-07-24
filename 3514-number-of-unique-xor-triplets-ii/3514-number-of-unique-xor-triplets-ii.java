class Solution {
    public int uniqueXorTriplets(int[] nums) {
        boolean[] uniqueNums = new boolean[2048];
        for (int x : nums) {
            uniqueNums[x] = true;
        }

        boolean[] set1 = new boolean[2048];
        set1[0] = true;

        for (int round = 0; round < 3; round++) {
            boolean[] nextSet = new boolean[2048];
            for (int i = 0; i < 2048; i++) {
                if (set1[i]) {
                    for (int x = 0; x < 2048; x++) {
                        if (uniqueNums[x]) {
                            nextSet[i ^ x] = true;
                        }
                    }
                }
            }
            set1 = nextSet;
        }

        int count = 0;
        for (boolean b : set1) {
            if (b)
                count++;
        }

        return count;
    }
}