class Solution {
public:
    int lengthOfLastWord(string s) {
        int counting=0, count=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '&& counting) break;
            else if(s[i]!=' '){
                counting=1;
                count++;
            }
        }
        return count;
    }
};