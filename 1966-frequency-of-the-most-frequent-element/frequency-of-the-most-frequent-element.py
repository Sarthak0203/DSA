class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        l=0
        r=0
        maxFreq=0
        windowSum=0

        for r in range (len(nums)):
            windowSum+=nums[r]
            while(nums[r]*(r-l+1) > windowSum+k):
                windowSum-=nums[l]
                l+=1
            
            maxFreq = max(maxFreq, r-l+1)
        
        return maxFreq
        