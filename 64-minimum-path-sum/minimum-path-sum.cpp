class Solution {

private:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int top = f(i-1, j, grid, dp);
        int left = f(i, j-1, grid, dp);

        return dp[i][j] = grid[i][j] + min(top, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = (i>0)?dp[i-1][j]:INT_MAX;
                    int left = (j>0)?dp[i][j-1]:INT_MAX;
                    dp[i][j] = grid[i][j] + min(left, up);
                }
            }
        }
        return dp[m-1][n-1];
        // return f(m-1, n-1, grid, dp);
    }
};