class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left[] = new int[n];
        int right[] = new int[n];
        for(int i = 0; i < n; ++i){
            left[i] = right[i] = height[i];
        }
        for(int i = 1; i < n; ++i){
            left[i] = Math.max(left[i], left[i - 1]);
        }
        for(int i = n - 2; i >= 0; --i){
            right[i] = Math.max(right[i], right[i + 1]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            // System.out.println(left[i] + " " + height[i] + " " + right[i]);
            ans += Math.min(left[i], right[i]) - height[i];
        }
        return ans;
    }
}
