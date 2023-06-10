class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 1;
        for(int i = 1; i < nums.length; ++i){
            if(nums[i] == nums[i - 1]){
                continue;
            }
            nums[k] = nums[i];
            ++k;
        }
        return k;
    }
}
