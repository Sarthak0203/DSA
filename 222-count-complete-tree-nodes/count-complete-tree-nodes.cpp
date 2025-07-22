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
    int count(TreeNode* root, int& c){
        if(!root) return 0;
        c++;
        count(root->left, c);
        count(root->right, c);
        return c;
    }

public:
    int countNodes(TreeNode* root) {
        int c=0;
        return count(root, c);
    }
};