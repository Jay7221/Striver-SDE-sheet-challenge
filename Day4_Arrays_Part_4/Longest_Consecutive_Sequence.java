class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Boolean> isPresent = new HashMap<>();
        HashMap<Integer, Boolean> vis = new HashMap<>();
        for(int elem : nums){
            vis.put(elem, false);    
        }
        int ans = 0;
        for(int elem : nums){
            if(vis.get(elem)){
                continue;
            }
            int cur = 1;
            while(vis.containsKey(elem - 1)){
                --elem;
            }
            vis.replace(elem, true);
            while(vis.containsKey(elem + 1)){
                ++elem;
                ++cur;
                vis.replace(elem, true);
            }
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
