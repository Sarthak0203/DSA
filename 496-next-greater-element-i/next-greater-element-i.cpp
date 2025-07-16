#include <vector>
#include <algorithm> 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);  
        for (int i = 0; i < nums1.size(); i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end()) {
                int j = distance(nums2.begin(), it); 
                for (int k = j + 1; k < nums2.size(); k++) {
                    if (nums2[k] > nums1[i]) {
                        ans[i] = nums2[k];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
