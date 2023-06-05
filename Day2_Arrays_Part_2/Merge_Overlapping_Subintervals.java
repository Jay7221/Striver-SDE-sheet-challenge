class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int l = intervals[0][0], r = intervals[0][1];

        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < intervals.length; ++i){
            int ll = intervals[i][0];
            int rr = intervals[i][1];
            if(ll > r){
                ArrayList<Integer> cur = new ArrayList<Integer>();
                cur.add(l);
                cur.add(r);
                ans.add(cur);
                l = ll;
                r = rr;
            }
            r = Math.max(r, rr);
        }
        ArrayList<Integer> cur = new ArrayList<Integer>();
        cur.add(l);
        cur.add(r);
        ans.add(cur);
                
        n = ans.size();
        int[][] fans = new int[n][2];
        for(int i = 0; i < fans.length; ++i){
            fans[i][0] = ans.get(i).get(0);
            fans[i][1] = ans.get(i).get(1);
        }
        return fans;
    }
}
