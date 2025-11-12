class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x<0 else 1
        x= abs(x)
        num = int(str(x)[::-1])*sign
        if(num > 2147483648 or num < -2147483647):
            return 0
        else:
            return num