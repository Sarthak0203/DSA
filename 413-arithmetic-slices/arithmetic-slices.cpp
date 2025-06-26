class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int count = 0, cur = 0;
        for(int i=2;i<n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                cur++;
                count+=cur;
            }
            else cur = 0;
        }
        return count;
    }
};