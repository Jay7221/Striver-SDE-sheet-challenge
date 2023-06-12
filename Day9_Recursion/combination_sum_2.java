class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> cur = new ArrayList<Integer>();
        int sum = 0;
        Arrays.sort(candidates);
        helper(candidates, target, 0, cur, ans, 0);
        return ans;
    }
    void helper(int[] arr, int tar, int index, List<Integer> cur, List<List<Integer>> ans, int sum){
        if(sum == tar){
            ans.add(new ArrayList<Integer>(cur));
            return;
        }
        if(sum > tar){
            return;
        }
        for(int i = index; i < arr.length; ++i){
            if((i > index) && (arr[i] == arr[i - 1])){
                continue;
            }
            sum += arr[i];
            cur.add(arr[i]);
            helper(arr, tar, i + 1, cur, ans, sum);
            sum -= arr[i];
            cur.remove(cur.size() - 1);
        }
    }
}
