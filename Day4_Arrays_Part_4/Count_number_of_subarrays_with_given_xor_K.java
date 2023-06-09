public class Solution {
    public int solve(int[] A, int B) {
        HashMap<Integer, Integer> ind = new HashMap<>();
        int curXor = 0;
        ind.put(curXor, 1);
        int ans = 0;
        for(int i = 0; i < A.length; ++i){
            curXor ^= A[i];
            int reqXor = curXor ^ B;
            if(ind.containsKey(reqXor)){
                ans += ind.get(reqXor);
            }
            if(ind.containsKey(curXor)){
                int k = ind.get(curXor);
                ind.put(curXor, k + 1);
            }else{
                ind.put(curXor, 1);
            }
        }
        return ans;
    }
}
