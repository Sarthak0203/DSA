class Solution {
public:
    string longestPrefix(string pat) {
        vector<int> lps(pat.size(),0);
        for(int i=1;i<pat.size();i++){
            int j=lps[i-1];
            while(j>0 && pat[i]!=pat[j]){
                j=lps[j-1];
            }
            if(pat[i]==pat[j]) j++;
            lps[i]=j;
        }
        return pat.substr(0,lps[pat.size()-1]);
    }
};