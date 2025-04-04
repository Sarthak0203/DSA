class Solution {
public:
    int countSegments(string s) {
        if(s.size()<1) return 0;
        int a=0,ans=0;
        if(s[0]!=' ') ans++;
        for(int i=0;i<s.size();i++){
           if(s[i]==' '){
            a=1;
           }
           else if(a==1 && s[i]!=' '){
            ans++;
            a=0;
           }
        }
        return ans;
    }
};