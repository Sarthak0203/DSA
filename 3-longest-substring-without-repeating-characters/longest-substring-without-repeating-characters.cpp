class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int i=0, j=0;
        int currLength=0, maxLength=INT_MIN;
        unordered_multiset<char> mp;
        while(j<n){
            if(mp.find(s[j]) == mp.end()){
                mp.insert(s[j]);
                maxLength = max(maxLength, j-i+1);
                j++;
            }
            else{
                mp.erase(s[i]);
                i++;
            }
        }
        return maxLength;
    }
};