class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int> &nums, vector<int>& temp, int i){
        if(i>=nums.size()){
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(nums, temp, i+1);
        temp.pop_back();
        solve(nums, temp, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0);
        return result;
    }
};