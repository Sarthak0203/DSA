class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums) freq[num]++;
        int maxi = 0;
        for(auto& fre : freq){
            maxi = max(maxi, fre.second);
        }
        int maxe = 0;
        for(auto& fre : freq){
            if(fre.second == maxi) maxe++;
        }
        return maxe*maxi;
    }
};