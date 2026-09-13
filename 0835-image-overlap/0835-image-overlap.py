import collections
from typing import List

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        ones1 = []
        ones2 = []
        
        for r in range(n):
            for c in range(n):
                if img1[r][c] == 1:
                    ones1.append((r, c))
                if img2[r][c] == 1:
                    ones2.append((r, c))
                    
        translations = collections.Counter()
        max_overlap = 0
        
        for r1, c1 in ones1:
            for r2, c2 in ones2:
                vec = (r2 - r1, c2 - c1)
                translations[vec] += 1
                max_overlap = max(max_overlap, translations[vec])
                
        return max_overlap
        