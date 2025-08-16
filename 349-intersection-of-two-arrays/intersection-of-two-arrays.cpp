class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        vector<int> ans;

        for(int i=0; i<nums1.size(); i++){
            s1.insert(nums1[i]);
        }
        for(int j=0;j<nums2.size();j++){
            if(s1.find(nums2[j]) != s1.end()) s2.insert(nums2[j]);
        }
        for(auto& it : s2){
            ans.push_back(it);
        }
        return ans;
    }
};