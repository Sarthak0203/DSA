class Solution {
public:
    bool checkValidString(string s) {
        int minopen = 0, maxopen = 0;
        for(int it : s){
            if(it == '('){
                minopen++;
                maxopen++;
            }
            else if(it == ')'){
                minopen = max(0,minopen-1);
                maxopen--;
            }
            else{
                minopen = max(0, minopen-1);
                maxopen++;
            }
            if(maxopen<0) return false;
        }
        return minopen==0;
    }
};