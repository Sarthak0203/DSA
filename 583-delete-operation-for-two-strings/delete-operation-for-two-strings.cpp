class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word1[i]==word2[j]){
                    // dp[i][j]=1+dp[i-1][j-1];
                    if(i>0 && j>0){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1;
                    }
                }
                else{
                    int top = (i>0)?dp[i-1][j]:0;
                    int left = (j>0)?dp[i][j-1]:0;
                    dp[i][j]=max(left, top);
                }
            }
        }
        return (m+n) - 2*dp[m-1][n-1];
    }
};