class Solution {
    void solve(vector<int>& nums, int idx, int currentXOR, int &totalXOR) {
        if (idx == nums.size()) {
            totalXOR += currentXOR;
            return;
        }
        
        // Include the current element
        solve(nums, idx + 1, currentXOR ^ nums[idx], totalXOR);
        
        // Exclude the current element
        solve(nums, idx + 1, currentXOR, totalXOR);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int totalXOR = 0;
        solve(nums, 0, 0, totalXOR);
        return totalXOR;
    }
};
