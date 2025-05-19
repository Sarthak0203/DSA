class NumArray {

vector<int> seg;
vector<int> arr;
int n;

private:
    void build(int idx, int left, int right){
        if(left==right){
            seg[idx]=arr[left];
            return;
        }
        int mid=(left+right)/2;
        build(2*idx+1, left, mid);
        build(2*idx+2, mid+1, right);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int query(int idx, int low, int high, int l, int r){
        if(low>=l && high<=r) return seg[idx];
        if(low>r || high<l) return 0;

        int mid=(low+high)/2;
        int left=query(2*idx+1, low, mid, l, r);
        int right=query(2*idx+2, mid+1, high, l, r);
        return left+right;
    }

    void updateUntil(int idx, int low, int high, int i, int val){
        if(low==high){
            seg[idx] = val;
            return;
        }
        
        int mid=(low+high)/2;
        if(i<=mid){
            updateUntil(2*idx+1, low, mid, i, val);
        }
        else{
            updateUntil(2*idx+2, mid+1, high, i, val);
        }
        seg[idx]=seg[2*idx+1] + seg[2*idx+2];
    }

public:
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        seg.resize(n*4);
        build(0, 0, n-1);
    }
    
    void update(int index, int val) {
        updateUntil(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */