public class Solution {
    public static int NthRoot(int n, int m) {
        long l = 0, r = m;
        while(l < r){
            long mid = (l + r) / 2;
            if(Math.pow(mid, n) < m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(Math.pow(l, n) != m){
            l = -1;
        }
        return (int)l;
    }
}
