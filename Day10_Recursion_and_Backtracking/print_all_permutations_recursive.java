class Solution {
    void helper(int[] nums, boolean[] vis, List<Integer> cur, List<List<Integer>> ans){
        if(cur.size() == nums.length){
            ans.add(new ArrayList<>(cur));
        }else{
            for(int i = 0; i < nums.length; ++i){
                if(!vis[i]){
                    vis[i] = true;
                    cur.add(nums[i]);
                    helper(nums, vis, cur, ans);
                    cur.remove(cur.size() - 1);
                    vis[i] = false;
                }
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        List<Integer> cur = new ArrayList<Integer>();
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        boolean vis[] = new boolean[nums.length];
        helper(nums, vis, cur, ans);
        return ans;
    }
}
