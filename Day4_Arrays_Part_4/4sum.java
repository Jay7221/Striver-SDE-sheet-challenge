class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for(int i = 0; i < n; ++i){
            if((i > 0) && (nums[i] == nums[i - 1])){
                continue;
            }
            for(int j = i + 1; j < n; ++j){
                if((j > i + 1) && (nums[j] == nums[j - 1])){
                    continue;
                }
                for(int k = j + 1; k < n - 1; ++k){
                    if((k > j + 1) && (nums[k] == nums[k - 1])){
                        continue;
                    }
                    long req = target - (nums[i] + 0l + nums[j] + nums[k]);
                    int l = k + 1, r = n - 1;
                    while(l < r){
                        int mid = (l + r) / 2;
                        if(nums[mid] < req){
                            l = mid + 1;
                        }else{
                            r = mid;
                        }
                    }
                    if(nums[l] == req){
                        List<Integer> cur = new ArrayList<Integer>();
                        cur.add(nums[i]);
                        cur.add(nums[j]);
                        cur.add(nums[k]);
                        cur.add(nums[l]);
                        ans.add(cur);
                    }
                }
            }
        }
        return ans;
    }
}
