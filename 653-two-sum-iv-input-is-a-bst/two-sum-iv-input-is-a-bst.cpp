class Solution {
private:
    void inorder(TreeNode* node, set<int>& st) {
        if (!node) return;
        inorder(node->left, st);
        st.insert(node->val);
        inorder(node->right, st);
    }

    bool inorderT(TreeNode* node, set<int>& st, int target) {
        if (!node) return false;
        if (inorderT(node->left, st, target)) return true;
        if (st.find(target - node->val) != st.end() && target - node->val != node->val)
            return true;
        if (inorderT(node->right, st, target)) return true;
        return false;
    }

public:
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        inorder(root, st);
        return inorderT(root, st, k);
    }
};
