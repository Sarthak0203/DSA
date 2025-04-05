class Solution {

void solve(vector<int>& comb, vector<vector<int>>& res, int n, int k, int s){
    if(comb.size()==k){
        res.push_back(comb);
        return;
    }
    for(int i=s; i<=n;i++){
        comb.push_back(i);
        solve(comb, res, n, k, i+1);
        comb.pop_back();
        // solve(comb, res, n, k, i+1);
    }
}

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        vector<vector<int>> res;
        solve(comb, res, n, k, 1);
        return res;
    }
};