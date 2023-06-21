public class Solution {
    public int[] solve(int a[], int b[], int c) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        int n = a.length;
        Arrays.sort(a);
        Arrays.sort(b);
        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(pq.size() < c){
                    pq.add(a[i] + b[j]);
                    continue;
                }
                if((a[i] + b[j]) > pq.peek()){
                    pq.remove();
                    pq.add(a[i] + b[j]);
                }else{
                    break;
                }
            }
        }
        int ans[] = new int[c];
        for(int i = c - 1; i >= 0; --i){
            ans[i] = pq.poll();
        }
        return ans;
    }
}

