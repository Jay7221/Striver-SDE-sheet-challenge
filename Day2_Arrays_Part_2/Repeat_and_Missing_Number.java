public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int[] repeatedNumber(final int[] A) {
        long x = 0, y = 0, z = 0;
        for(int i = 0; i < A.length; ++i){
            x += (A[i] - (i + 1));
            y += (A[i] - (i + 1)) * 1l * (A[i] + (i + 1));
        }
        z = y / x;
        int a = (int)((z + x) / 2);
        int b = (int)((z - x) / 2);
        int ans[] = new int[]{a, b};
        return ans;
    }
}
