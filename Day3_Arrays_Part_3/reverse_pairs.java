class Solution {
    public int reversePairs(int[] nums) {
        return helper(nums, 0, nums.length - 1);   
    }
    public boolean compare(int a, int b){
        return (((a >> 1) > b) || (((a >> 1) == b) && ((a & 1) == 1)));
    }
    public int helper(int[] arr, int l, int r){
        if(l == r){
            return 0;
        }
        int mid = (l + r) / 2;
        int ans = helper(arr, l, mid) + helper(arr, mid + 1, r);
        int cur = mid + 1;
        for(int i = l; i <= mid; ++i){
            while((cur <= r) && compare(arr[i], arr[cur])){
                ++cur;
            }
            ans += cur - (mid + 1);
        }
        Arrays.sort(arr, l, r + 1);
        return ans;
    }
}
