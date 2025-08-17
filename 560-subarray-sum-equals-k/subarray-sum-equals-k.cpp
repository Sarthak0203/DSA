class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            for(int j=i;j<nums.size();j++){
                if(i!=j){
                    cur+=nums[j];
                }
                if(cur==k) count++;
            }
        }
        return count;
    }
};