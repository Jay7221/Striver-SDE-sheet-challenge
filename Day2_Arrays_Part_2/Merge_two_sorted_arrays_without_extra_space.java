class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int l = m - 1, r = n - 1;
        for(int i = (n + m - 1); i >= 0; --i){
            if((l > -1) && (r > -1)){
                if(nums1[l] >= nums2[r]){
                    nums1[i] = nums1[l];
                    --l;
                }else{
                    nums1[i] = nums2[r];
                    --r;
                }
            }else{
                if(l > -1){
                    nums1[i] = nums1[l];
                    --l;
                }else{
                    nums1[i] = nums2[r];
                    --r;
                }
            }
            
        }
    }
}
