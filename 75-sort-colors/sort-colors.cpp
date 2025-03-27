class Solution {
private:
    // void quickSort(vector<int>& nums, int low, int high) {
    //     if (low < high) {
    //         int pivot = nums[high];
    //         int i = low - 1;
    //         for (int j = low; j < high; j++) {
    //             if (nums[j] < pivot) {
    //                 i++;
    //                 swap(nums[i], nums[j]);
    //             }
    //         }
    //         swap(nums[i + 1], nums[high]);
    //         int pi = i + 1;

    //         quickSort(nums, low, pi - 1);
    //         quickSort(nums, pi + 1, high);
    //     }
    // }


    void sorts(vector<int>& nums){
        int n=nums.size();
        int low=0, high=n-1, mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

public:
    void sortColors(vector<int>& nums) { 
        // quickSort(nums, 0, nums.size() - 1); 
        sorts(nums);
    }
};