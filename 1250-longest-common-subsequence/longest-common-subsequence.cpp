class Solution {

private:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]=1+f(i-1, j-1, s1, s2, dp);
        else return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(text1[i]==text2[j]){
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
        return dp[m-1][n-1];
        // return f(m-1, n-1, text1, text2, dp);
    }
};