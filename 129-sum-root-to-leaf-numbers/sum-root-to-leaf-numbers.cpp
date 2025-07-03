/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    void dfs(TreeNode* root, int& total, int currentSum, vector<int>& path) {
        if (!root) return;

        currentSum = (currentSum*10) + root->val;
        path.push_back(root->val);

        if (!root->left && !root->right ) {
            total+=currentSum;
        }

        // Recurse on left and right children
        dfs(root->left, total, currentSum, path);
        dfs(root->right, total, currentSum, path);

        // Backtrack
        path.pop_back();
    }

public:
    int sumNumbers(TreeNode* root) {
        int total = 0, currentSum = 0;
        vector<int> path;
        dfs(root, total, currentSum, path);
        return total;
    }
};