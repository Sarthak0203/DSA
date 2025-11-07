class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long int l=0, r=0, maxFreq=0, sum=0, n=nums.size();
        for(r;r<n;r++){
            sum+=nums[r];
            if(l+1<=r && nums[r]*(r-l+1) > sum+k){
                sum=sum-nums[l];
                l++;
            }
            maxFreq = max(maxFreq, r-l+1);
        }
        return maxFreq;
    }
};