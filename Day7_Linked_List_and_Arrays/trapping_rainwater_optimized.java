class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int l = 0;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(height[i] > height[l]){
                ans += height[l] * (i - l) - sum;
                sum = 0;
                l = i;
            }
            sum += height[i];
        }
        int r = n - 1;
        sum = 0;
        for(int i = n - 1; i >= 0; --i){
            if(height[i] >= height[r]){
                ans += height[r] * (r - i) - sum;
                sum = 0;
                r = i;
            }
            sum += height[i];
        }
        return ans;
    }
}
