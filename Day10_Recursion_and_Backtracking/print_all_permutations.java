class Solution {
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length;
        int nf = 1;
        for(int i = 1; i <= n; ++i){
            nf *= i;
        }
        for(int c = 0; c < nf; ++c){
            List<Integer> p = new ArrayList<Integer>();
            for(int x : nums){
                p.add(x);
            }
            ans.add(p);

            for(int i = n - 2; i >= 0; --i){
                if(nums[i] < nums[i + 1]){
                    int k = i + 1;
                    for(int j = i + 1; j < n; ++j){
                        if(nums[j] > nums[i]){
                            k = j;
                        }
                    }
                    int tmp = nums[i];
                    nums[i] = nums[k];
                    nums[k] = tmp;

                    Arrays.sort(nums, i + 1, n);
                    break;
                }
            }
        }
        return ans;
    }
}
