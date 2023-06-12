class Solution {
    List<List<Integer>> subsets;
    void helper(int nums[], int index, List<Integer> cur){

        subsets.add(new ArrayList<Integer>(cur));
        
        for(int i = index; i < nums.length; ++i){
            if(i > index && nums[i] == nums[i - 1]){
                continue;
            }
            cur.add(nums[i]);
            helper(nums, i + 1, cur);
            cur.remove(cur.size() - 1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums){
        Arrays.sort(nums);
        List<Integer> cur = new ArrayList<Integer>();
        subsets = new ArrayList<List<Integer>>();
        helper(nums, 0, cur);
        return subsets;
    }
}
