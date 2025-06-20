class Solution {
    int helper(vector<int>& prices, int ind, int buy, int cap, int n, vector<vector<vector<int>>>& dp){
        if(ind == n || cap == 0){
            return 0;
        }
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if(buy == 0){
            // We can buy
            profit = max(
                helper(prices, ind+1, 0, cap, n, dp),                
                helper(prices, ind+1, 1, cap, n, dp) - prices[ind]  
            );
        } else {
            // We can sell
            profit = max(
                helper(prices, ind+1, 1, cap, n, dp),                
                prices[ind] + helper(prices, ind+1, 0, cap-1, n, dp) 
            );
        }

        return dp[ind][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, 0, 2, n, dp); 
    }
};
