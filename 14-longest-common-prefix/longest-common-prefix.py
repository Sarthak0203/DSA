class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs = sorted(strs)
        first = strs[0]
        last = strs[len(strs)-1]
        ans=""

        for i in range(min(len(first), len(last))):
            if(first[i] == last[i]):
                ans = ans+first[i]
            else:
                return ans
        
        return ans