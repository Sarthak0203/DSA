class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int> &nums, vector<int>& temp, int i){

        if(i==nums.size()){
            if(find(result.begin(), result.end(), temp)==result.end()){
                result.push_back(temp);
            }
            return;
        }
        
        temp.push_back(nums[i]);
        solve(nums, temp, i+1);
        temp.pop_back();
        solve(nums, temp, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, temp, 0);
        return result;
    }
};

