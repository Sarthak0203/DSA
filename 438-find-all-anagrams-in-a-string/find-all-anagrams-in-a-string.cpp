class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> fp(26,0), fs(26,0);
        vector<int> ans;

        for(char ch : p){
            fp[ch-'a']++;
        }
        
        for(int i=0;i<n;i++){
            fs[s[i] - 'a']++;
            if(i>=m) fs[s[i-m] - 'a']--;
            if(i>=m-1 && fp == fs) ans.push_back(i-m+1);
        }
        return ans;
    }
};