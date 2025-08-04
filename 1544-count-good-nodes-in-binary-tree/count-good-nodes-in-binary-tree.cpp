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
int c=0;
private:
    int dfs(TreeNode* root, int x){
        if(!root) return 0;
        // int c=0;
        if(root->val >= x){
            c++;
            x=root->val;
        }
        dfs(root->left, x);
        dfs(root->right, x);
        return c;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};