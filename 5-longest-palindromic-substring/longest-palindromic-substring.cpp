class Solution {

private:
    bool checkifpal(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxL=0;
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                if(checkifpal(s,i,j)){
                    if(j-i+1>maxL){
                        maxL=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxL);
    }
};