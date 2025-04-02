class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, vector<int>& temp, int target, int i) {
        if (target == 0) {  // If target is met, add the current combination
            result.push_back(temp);
            return;
        }
        if (i >= candidates.size() || target < 0) return; // Base case: out of bounds or negative target

        // Include the current element
        temp.push_back(candidates[i]);
        solve(candidates, temp, target - candidates[i], i); // Allow same element

        // Exclude the current element
        temp.pop_back();
        solve(candidates, temp, target, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear(); // Clear previous results
        vector<int> temp;
        solve(candidates, temp, target, 0);
        return result;
    }
};
