func twoSum(nums []int, target int) []int {
    // ans:=make([]int, 2)
    for i:=0;i<len(nums);i++{
        for j:=0;j<len(nums);j++{
            if(i!=j && nums[i]+nums[j] == target){
                return[] int {i, j}
            }
        }
    }
    return nil
}