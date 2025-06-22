class Solution {
private:
    int n;
    vector<vector<vector<int>>> dp;

    int f(int i, int j, int x, vector<vector<int>>& grid) {
        int y = i + j - x;  // Because steps taken = i + j = x + y

        // Boundary or thorn checks
        if (i >= n || j >= n || x >= n || y >= n || grid[i][j] == -1 || grid[x][y] == -1) return -1e9;

        // Reached destination
        if (i == n - 1 && j == n - 1) return grid[i][j];

        // Already computed
        if (dp[i][j][x] != -1) return dp[i][j][x];

        int cherries = grid[i][j];
        if (i != x || j != y) cherries += grid[x][y];

        // Try all 4 combinations
        int a = f(i + 1, j, x + 1, grid);
        int b = f(i, j + 1, x, grid);
        int c = f(i + 1, j, x, grid);
        int d = f(i, j + 1, x + 1, grid);

        cherries += max({a, b, c, d});

        return dp[i][j][x] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, f(0, 0, 0, grid));
    }
};
