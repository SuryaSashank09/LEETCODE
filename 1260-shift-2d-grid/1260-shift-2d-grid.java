class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int totalElements = m * n;
        k = k % totalElements;
        
        List<List<Integer>> result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            List<int[]> row = new ArrayList<>();
            List<Integer> currentRow = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                int currentFlatIndex = i * n + j;
                int originalFlatIndex = (currentFlatIndex - k + totalElements) % totalElements;
                
                int origRow = originalFlatIndex / n;
                int origCol = originalFlatIndex % n;
                
                currentRow.add(grid[origRow][origCol]);
            }
            result.add(currentRow);
        }
        
        return result;
    }
}