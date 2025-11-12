class Solution:
    def countPrimes(self, n: int) -> int:
        if(n==0 or n==1 or n==2):
            return 0
        isPrime = [True]*n
        isPrime[0] = isPrime[1] = False
        count=0
        for i in range(2, n):
            if(isPrime[i]):
                count+=1
                for j in range(2*i, n, i):
                    isPrime[j]=False
        
        return count