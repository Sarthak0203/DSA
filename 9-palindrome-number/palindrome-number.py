class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x<0):
            return False
        num=x
        rev=0
        while(x>0):
            y=x%10
            rev = rev*10+y
            x//=10
        return rev==num
        