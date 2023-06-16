class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[l] > nums[mid]){
                r = mid;
            }else{
                if(nums[mid] > nums[r]){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
        }
        int k = l;
        l = k;
        r = n - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(nums[l] == target){
            return l;
        }
        l = 0;
        r = k - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        if(nums[l] == target){
            return l;
        }
        return -1;
    }
}
