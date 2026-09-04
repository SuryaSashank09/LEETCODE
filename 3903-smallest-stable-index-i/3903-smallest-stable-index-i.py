class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        
        suffix_min = [0] * n
        current_min = float('inf')
        for i in range(n - 1, -1, -1):
            current_min = min(current_min, nums[i])
            suffix_min[i] = current_min
            
        current_max = float('-inf')
        for i in range(n):
            current_max = max(current_max, nums[i])
            
            if current_max - suffix_min[i] <= k:
                return i
                
        return -1