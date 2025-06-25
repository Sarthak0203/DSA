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
    bool f(long p, long q, TreeNode* root){
        if(!root) return true;
        if(root->val <= p || root->val >= q) return false;
        return (f(p, root->val, root->left) && f(root->val, q, root->right));
    }

public:
    bool isValidBST(TreeNode* root) {
        return f(LONG_MIN, LONG_MAX, root);
    }
};