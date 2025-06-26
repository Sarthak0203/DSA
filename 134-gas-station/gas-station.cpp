class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int totalG = 0;
        int currGas = 0;

        for(int i=0;i<gas.size();i++){
            int fuel = gas[i]-cost[i];
            totalG += fuel;
            currGas += fuel;

            if(currGas < 0){
                currGas = 0;
                start = i+1;
            }
        }
        return totalG < 0 ? -1 : start;
    }
};