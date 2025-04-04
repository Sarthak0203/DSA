class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;

        int l=0, r=x, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            long long square=static_cast<long long>(mid)*mid;
            if(square>x) r=mid-1;
            else if(square==x) return mid;
            else l=mid+1;
        }
        return static_cast<int>(std::round(r));
    }
};