class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int cur = nums[0];
        for(int i = 0; i < nums.length; ++i){
            sum = nums[i] + Math.max(sum, 0);
            cur = Math.max(cur, sum);
        }
        return cur;
    }
}
