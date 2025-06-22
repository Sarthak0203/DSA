class Solution {
private:
    int m, n;
    vector<vector<vector<int>>> dp;

    int f(int row, int col1, int col2, vector<vector<int>>& grid) {
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return -1e8;  // out of bounds

        if (row == m) return 0; // done

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cherries = grid[row][col1];
        if (col1 != col2)
            cherries += grid[row][col2];

        int maxNext = 0;
        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                maxNext = max(maxNext, f(row + 1, col1 + d1, col2 + d2, grid));
            }
        }

        return dp[row][col1][col2] = cherries + maxNext;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0, 0, n - 1, grid); // robot1 at (0,0), robot2 at (0,n-1)
    }
};
