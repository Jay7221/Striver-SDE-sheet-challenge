public class Solution {
    int get(int x, int[][] A){
        int n = A.length;
        int m = A[0].length;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(A[i][0] > x){
                continue;
            }
            int l = 0, r = m - 1;
            while(l < r){
                int mid = (l + r + 1) / 2;
                if(A[i][mid] > x){
                    r = mid - 1;
                }else{
                    l = mid;
                }
            }
            ans += l + 1;
        }
        return ans;
    }
    public int findMedian(int[][] A) {
        int l = 0, r = 1000000000;
        int n = A.length * A[0].length;
        while(l < r){
            int mid = (l + r) / 2;
            if(get(mid, A) <= n / 2){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        // System.out.println(l + " " + get(l, A));
        return l;
    }
}

