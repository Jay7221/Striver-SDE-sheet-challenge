class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int l = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0){
                if(l < i){
                    nums[i] ^= nums[l];
                    nums[l] ^= nums[i];
                    nums[i] ^= nums[l];    
                }
                ++l;
            }
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1){
                if(l < i){
                    nums[i] ^= nums[l];
                    nums[l] ^= nums[i];
                    nums[i] ^= nums[l];
                }
                ++l;
            }
        }
    }
}
