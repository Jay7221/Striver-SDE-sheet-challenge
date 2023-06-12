class Solution {
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> cur = new ArrayList<Integer>();
        List<List<Integer>> combs = new ArrayList<List<Integer>>();
        helper(candidates, target, 0, cur, combs, 0);
        return combs;
    }
    void helper(int[] arr, int tar, int index, List<Integer> cur, List<List<Integer>> ans, int sum){
        if(index == arr.length){
            if(sum == tar){
                ans.add(new ArrayList<Integer>(cur));
            }
            return;
        }
        int nsum = sum;
        helper(arr, tar, index + 1, cur, ans, sum);
        while(nsum + arr[index] <= tar){
            nsum += arr[index];
            cur.add(arr[index]);
            helper(arr, tar, index + 1, cur, ans, nsum);
        }
        while(nsum > sum){
            nsum -= arr[index];
            cur.remove(cur.size() - 1);
        }
    }
}
