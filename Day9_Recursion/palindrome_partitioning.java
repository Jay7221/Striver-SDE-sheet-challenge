class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<List<String>>();
        List<String> cur = new ArrayList<String>();
        helper(s, 0, cur, ans);
        return ans;
    }
    void helper(String s, int index, List<String> cur, List<List<String>> ans){
        if(index == s.length()){
            ans.add(new ArrayList<String>(cur));
        }
        for(int i = index; i < s.length(); ++i){
            if(isPal(s, index, i)){
                cur.add(s.substring(index, i + 1));
                helper(s, i + 1, cur, ans);
                cur.remove(cur.size() - 1);
            }
        }
    }
    boolean isPal(String s, int l, int r){
        while(l < r){
            if(s.charAt(l) != s.charAt(r)){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
}
