class Solution {
    public int[] twoSum(int[] nums, int target) {
        int tmp[] = new int[nums.length];
        for(int i = 0; i < nums.length; ++i){
            tmp[i] = nums[i];
        }
        Arrays.sort(nums);
        int l = 0, r = nums.length - 1;
        while(l < r){
            if(nums[l] + nums[r] < target){
                ++l;
            }else if(nums[l] + nums[r] > target){
                --r;
            }else{
                break;
            }
        }
        for(int i = 0; i < nums.length; ++i){
            if(tmp[i] == nums[l]){
                l = i;
                break;
            }
        }
        for(int i = 0; i < nums.length; ++i){
            if((l != i) && tmp[i] == nums[r]){
                r = i;
                break;
            }
        }
        return (new int[]{l, r});
    }
}
