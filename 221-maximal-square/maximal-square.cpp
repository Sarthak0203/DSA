class Solution {

int f(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp){
    if(i>=matrix.size() || j>=matrix[0].size()) return 0;
    if(dp[i][j]>=0) return dp[i][j];
    if(matrix[i][j] == '0') return dp[i][j] = 0;

    dp[i][j] = min(min(f(i+1, j, matrix, dp), f(i, j+1, matrix, dp)), f(i+1, j+1, matrix, dp)) +1;
    return dp[i][j];
}

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, f(i, j, matrix, dp));
            }
        }
        return res*res;
    }
};