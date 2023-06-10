class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i < n - 2; ++i){
            if((i > 0) && (nums[i] == nums[i - 1])){
                continue;
            }
            for(int j = i + 1; j < n - 1; ++j){
                if((j > i + 1) && (nums[j] == nums[j - 1])){
                    continue;
                }
                int l = j + 1, r = n - 1;
                while(l < r){
                    int mid = (l + r) / 2;
                    int sum = nums[i] + nums[j] + nums[mid];
                    if(sum < 0){
                        l = mid + 1;
                    }else{
                        r = mid;
                    }
                }
                int k = l;
                if(nums[i] + nums[j] + nums[k] == 0){
                    List<Integer> cur = new ArrayList<Integer>();
                    cur.add(nums[i]);
                    cur.add(nums[j]);
                    cur.add(nums[k]);
                    ans.add(cur);
                }
            }
        }
        return ans;
    }
}
