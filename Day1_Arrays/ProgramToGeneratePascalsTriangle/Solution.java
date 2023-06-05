class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> p = new ArrayList<List<Integer>>();
        ArrayList<Integer> cur = new ArrayList<Integer>();
        cur.add(1);
        p.add(cur);
        if(numRows == 1){
            return p;
        }
        for(int cnt = 1; cnt < numRows; ++cnt){
            ArrayList<Integer> next = new ArrayList<Integer>();
            next.add(1);
            for(int i = 1; i < cur.size(); ++i){
                next.add(cur.get(i - 1) + cur.get(i));
            }
            next.add(1);
            p.add(next);
            cur = next;
        }
        return p;
    }
}
