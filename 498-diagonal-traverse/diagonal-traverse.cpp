class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, vector<int>> diagMap;
        vector<int> result;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diagMap[i + j].push_back(mat[i][j]);
            }
        }

        for (int k = 0; k <= m + n - 2; k++) {
            if (k % 2 == 0) {
                reverse(diagMap[k].begin(), diagMap[k].end());
            }
            for (int val : diagMap[k]) {
                result.push_back(val);
            }
        }

        return result;
    }
};
