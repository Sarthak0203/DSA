class Solution {
public:

    int n;
    bool palindrome(string s){
        int l=0, r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string s, int i, vector<vector<string>>& result, vector<string> temp){
        if(i==n){
            result.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if (palindrome(s.substr(i, j - i + 1))) {
                temp.push_back(s.substr(i, j - i + 1));
                backtrack(s, j + 1, result, temp);
                temp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        n=s.length();
       vector<vector<string>> result;
       vector<string> temp;

       backtrack(s, 0, result, temp);
       return result; 
    }
};