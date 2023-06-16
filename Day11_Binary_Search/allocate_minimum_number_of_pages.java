public class Solution {
    boolean check(int arr[], int x, int b){
        int numS = 1;
        int cur = 0;
        for(int elem : arr){
            if(elem > x){
                return false;
            }
            if(elem + cur > x){
                cur = 0;
                ++numS;
            }
            cur += elem;
        }
        return (numS <= b);
    }
    public int books(int[] A, int B) {
        if(B > A.length){
            return -1;
        }
        int lo = 0, hi = 1000000000;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(check(A, mid, B)){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
}

