class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            d[i]=d.get(i,0)+1
        sum=0
        for i in nums:
            if d[i]==1:
                sum+=i
        return sum
        