class Solution {
    public int majorityElement(int[] nums) {
        int cur = nums[0], freq = 0;
        for(int elem : nums){
            if(elem == cur){
                ++freq;
            }else{
                if(freq == 0){
                    cur = elem;
                    freq = 1;
                }else{
                    --freq;
                }
            }
        }
        return cur;
    }
}
