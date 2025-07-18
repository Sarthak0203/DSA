class Solution {

private:
    int f(int n, vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int mini = INT_MAX;

        for(int i=1;i*i<=n;i++){
            int result = 1 + f(n-i*i, dp);
            mini = min(mini, result);
        }
        return dp[n] = mini;
    }

public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};