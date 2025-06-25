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

int maxSum = INT_MIN;

private:
    int f(TreeNode* root){

        if(!root) return 0;
        // if(!root->left && !root->right) return root->val;


        int leftSum = root->left ? max(0, f(root->left)) :0;
        int rightSum = root->right ? max(0, f(root->right)):0;
        int curSum = root->val + leftSum + rightSum;
        maxSum = max(maxSum, curSum);
        return root->val + max(leftSum, rightSum);

    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        f(root);
        return maxSum;
    }
};