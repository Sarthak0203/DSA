class Solution {
public:
    string reverseWords(string s) {
        string word;
        string res = "";
        reverse(s.begin(), s.end());
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        s = s.substr(i);
        stringstream ss(s);
        while (ss >> word) {
            reverse(word.begin(), word.end());
            res += word + " ";
        }
        if (!res.empty()) {
            res.pop_back();
        }
        
        return res;
    }
};
