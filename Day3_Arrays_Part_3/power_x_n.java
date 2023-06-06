class Solution {
    public double myPow(double x, int n) {
        double ans = 1;
        if(n < 0){
            ++n;
            x = 1 / x;
            ans = x;
            n = -n;
        }
        while(n > 0){
            if((n & 1) == 1){
                ans = x * ans;
            }
            x = x * x;
            n >>= 1;
        }
        return ans;
    }
}
