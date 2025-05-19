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
void inorder(TreeNode* root, string& s){
    if(!root) return;
    if(root->left == nullptr && root->right == nullptr){
        s+=to_string(root->val) + "_";
    }
    inorder(root->left, s);
    inorder(root->right, s);
    
}
public:

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        inorder(root1, s1);
        inorder(root2, s2);
        if(s1==s2) return true;
        else return false;
        return false;
    }
};