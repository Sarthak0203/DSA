class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vals;
        for(auto& row:grid){
            for(int elem:row){
                vals.push_back(elem);
            }
        }

        sort(vals.begin(), vals.end());

        for (int val : vals) {
            if (abs(val - vals[0]) % x != 0) {
                return -1;
            }
        }

        int median=vals[vals.size()/2];
        int count=0;

        for(int val:vals){
            count+=abs(val-median)/x;
        }
        return count;
    }
};