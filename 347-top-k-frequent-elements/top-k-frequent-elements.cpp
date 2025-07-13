class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums) freq[num]++;

        priority_queue<pair<int, int>> maxHeap;
        
        for(auto [num, f] : freq){
            maxHeap.push({f, num});
        }

        vector<int> ans;
        int x=0;
        while(x!=k){
            auto [f, num] = maxHeap.top();
            ans.push_back(num);
            maxHeap.pop();
            x++;
        }
        return ans;
    }
};