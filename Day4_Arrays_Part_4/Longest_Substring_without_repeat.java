class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0;
        HashMap<Character, Integer> ind = new HashMap<>();
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            char ch = s.charAt(i);
            if(ind.containsKey(ch)){
                l = Math.max(l, ind.get(ch) + 1);
            }
            ind.put(ch, i);
            ans = Math.max(ans, i - l + 1);
        }
        return ans;
    }
}
