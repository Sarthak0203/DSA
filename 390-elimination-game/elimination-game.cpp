class Solution {

private:
    int f(int n, int p){
        if(n==1) return 1;
        if(p==1 || n%2==1) return 2*f(n/2, 1-p);
        return 2*f(n/2, 1-p)-1;
    }
    

public:
    int lastRemaining(int n) {
        if(n==1) return 1;
        return f(n, 1);
    }
};