class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<Integer>();
        int cur1 = 0, cur2 = 1, freq1 = 0, freq2 = 0;
        for(int elem : nums){
            if(elem == cur1){
                ++freq1;
            }else if(elem == cur2){
                ++freq2;
                if(freq2 > freq1){
                    int tmp = freq1;
                    freq1 = freq2;
                    freq2 = tmp;

                    tmp = cur1;
                    cur1 = cur2;
                    cur2 = tmp;
                }
            }else{
                if(freq1 == 0){
                    cur1 = elem;
                    freq1 = 1;
                }else if(freq2 == 0){
                    cur2 = elem;
                    freq2 = 1;
                }else{
                    --freq1;
                    --freq2;
                }
            }
        }
        freq1 = freq2 = 0;
        for(int elem : nums){
            if(elem == cur1){
                ++freq1;
            }
            if(elem == cur2){
                ++freq2;
            }
        }
        if(freq1 > (nums.length) / 3){
            ans.add(cur1);
        }
        if(freq2 > (nums.length) / 3){
            ans.add(cur2);
        }
        return ans;
    }
}
