class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0) return 0;
        vector<int> dp(amount+1, INT_MAX-10);
        dp[0]=0;
        for(int i=1;i<amount+1;i++){
            for(int coin:coins){
                if((i-coin)>=0){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        int ans=dp[amount]>amount?-1 : dp[amount];
        return ans;
    }
};