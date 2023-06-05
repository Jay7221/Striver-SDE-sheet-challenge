class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int ans = 0;
        int cur = 0;
        for(int i = n - 1; i > 0; --i){
            prices[i] -= prices[i - 1];
        }
        for(int i = 1; i < n; ++i){
            cur = prices[i] + Math.max(0, cur);
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
