class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit : num){
            while(!st.empty() && k && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
            
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        ans=ans.substr(i);
        return ans==""?"0":ans;
    }
};