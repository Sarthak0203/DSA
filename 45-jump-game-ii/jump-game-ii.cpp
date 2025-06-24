class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)return 0; 
        int n = nums.size();
        int curreach = 0, maxreach = 0, jump=0;
        for(int i=0;i<n-1;i++){
            maxreach=max(maxreach, i+nums[i]);
            if(i>=curreach){
                jump++;
                curreach=maxreach;
            }
            if(i>=n-1) break;
        }
        return jump;
    }
};