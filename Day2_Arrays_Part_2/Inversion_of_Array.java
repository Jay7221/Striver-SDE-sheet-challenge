import java.util.* ;
import java.io.*; 
public class Solution {
    public static long helper(long arr[], int l, int r){
        if(l == r){
            return 0l;
        }
        int mid = (l + r) / 2;
        long ans = helper(arr, l, mid) + helper(arr, mid + 1, r);
        int cur = mid + 1;
        for(int i = l; i <= mid; ++i){
            while((cur <= r) && (arr[cur] < arr[i])){
                ++cur;
            }
            ans += cur - (mid + 1);
        }
        Arrays.sort(arr, l, r + 1);
        return ans;
    }
    public static long getInversions(long arr[], int n) {
        return helper(arr, 0, n - 1);
    }
}
