class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = 0;
        int currOnes = 0;
        int n=nums.size();
        totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int i=0, j=0;
        int maxCount =0, totalCount=0;

        vector<int> nums2;
        for(int i=0;i<2*n;i++){
            nums2.push_back(nums[i%n]);
        }

        while(j<2*n){
            if(nums2[j] == 1) currOnes++;
            
            if(j-i+1 > totalOnes){
                currOnes-=nums2[i];
                i++;
            }
            maxCount = max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }
};