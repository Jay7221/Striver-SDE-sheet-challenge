class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length - 1;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if((mid + 1 < n) && (nums[mid + 1] == nums[mid])){
                ++mid;
            }
            if(mid % 2 == 1){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return nums[l];
    }
}
