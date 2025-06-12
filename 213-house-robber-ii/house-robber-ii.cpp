class Solution {

private:
    long long f(vector<int>& arr){
        int n=arr.size();
        long long prev=arr[0], prev2=0;
        for(int i=1;i<n;i++){
            long long take=arr[i];
            if(i>1) take+=prev2;
            long long notTake=prev;

            long long curi=max(take, notTake);

            prev2=prev;
            prev=curi;
        }
        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(f(temp1), f(temp2));
    }
};