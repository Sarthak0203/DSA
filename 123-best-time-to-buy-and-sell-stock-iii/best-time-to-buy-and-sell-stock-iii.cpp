class Solution {
public:
    int dp[100001][2][2];
    int n;
    vector<int> nums;
    int rec(int i, int j, int k) {
        if (k >= 2 || i >= n)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int ans = 0;
        ans = max(ans, rec(i + 1, j, k));
        if (j == 0)
            ans = max(ans, rec(i + 1, 1, k) - nums[i]);
        if (j == 1)
            ans = max(ans, rec(i + 1, 0, k + 1) + nums[i]);
        dp[i][j][k] = ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        nums = prices;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0);
    }
};