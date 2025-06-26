class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int sum = 0;
        for(int i=0, j=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                mini = min(mini, i-j+1);
                sum-=nums[j++];
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};