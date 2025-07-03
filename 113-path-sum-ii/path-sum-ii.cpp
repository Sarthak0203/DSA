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
    void f(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& ans, int curSum) {
        if(!root) return;
        curSum+=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right &&  curSum == targetSum){
            ans.push_back(temp);
        }
        
        f(root->left, targetSum, temp, ans, curSum);
        f(root->right, targetSum, temp, ans, curSum);
        temp.pop_back();;
    }


public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(root, targetSum, temp, ans, 0);
        return ans;
    }
};