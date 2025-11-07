class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = {}
        maxi=0
        maxe=0
        for num in nums:
            freq[num] = freq.get(num, 0)+1
        
        for val in freq.values():
            maxi = max(maxi, val)
        
        for val in freq.values():
            if val == maxi:
                maxe+=1
        
        return maxe*maxi
        