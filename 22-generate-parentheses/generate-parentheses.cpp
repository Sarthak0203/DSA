class Solution {
public:
    void solve(string &op, int open, int close, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(op);
        return;
    }
    if(open > 0){
        op.push_back('(');
        solve(op, open-1, close, ans);
        op.pop_back();  // backtrack
    }
    if(close > open){
        op.push_back(')');
        solve(op, open, close-1, ans);
        op.pop_back();  // backtrack
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string op;
    solve(op, n, n, ans);
    return ans;
}

};