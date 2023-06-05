class Solution {
    public void nextPermutation(int[] nums) {
        boolean flag = false;
        int n = nums.length;
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] < nums[i + 1]){
                flag = true;
                int j = i + 1;
                for(int k = i + 1; k < n; ++k){
                    if(nums[k] > nums[i]){
                        j = k;
                    }
                }
                nums[i] ^= nums[j];
                nums[j] ^= nums[i];
                nums[i] ^= nums[j];
                int l = i + 1, r = n - 1;
                while(l < r){
                    nums[l] ^= nums[r];
                    nums[r] ^= nums[l];
                    nums[l] ^= nums[r];
                    ++l;
                    --r;
                }
                break;
            }
        }
        if(!flag){
            int l = 0, r = n - 1;
            while(l < r){
                nums[l] ^= nums[r];
                nums[r] ^= nums[l];
                nums[l] ^= nums[r];
                ++l;
                --r;
            }
        }
    }
}
