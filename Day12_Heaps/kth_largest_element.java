class Solution {
    int partition(int arr[], int l, int r){
        int cur = l;
        for(int i = l; i <= r; ++i){
            if(arr[i] < arr[cur]){
                int j = cur + 1;
                int tmp = arr[cur];
                arr[cur] = arr[i];
                ++cur;
                arr[i] = arr[cur];
                arr[cur] = tmp;
            }
        }
        return cur;
    }
    public int findKthLargest(int[] nums, int k) {
        int left = 0;
        int right = nums.length - 1;
        k = nums.length - k;
        while(left < right){
            int index = partition(nums, left, right);
            if(index == k){
                return nums[index];
            }
            if(index > k){
                right = index - 1;
            }else{
                left = index + 1;
            }
        }
        return nums[left];
    }
}
