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
    int inorderTraversal(TreeNode* root, int k) {
        int ans;
        stack<TreeNode*> st;
        for(int i=0;i<k;i++){
            while(root!=nullptr){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            ans=root->val;
            root=root->right;
        }
        return ans;

    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};