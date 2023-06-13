class Solution {
    void helper(boolean cur[][], int n, int row, List<List<String>> ans){
        if(row == n){
            List<String> board = new ArrayList<String>();
            for(int i = 0; i < n; ++i){
                StringBuilder s = new StringBuilder();
                for(int j = 0; j < n; ++j){
                    if(cur[i][j]){
                        s.append('Q');
                    }else{
                        s.append('.');
                    }
                }
                board.add(s.toString());
            }
            ans.add(board);
        }else{
            boolean ok[] = new boolean[n + 1];
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(cur[i][j]){
                        ok[j] = true;
                        int x = Math.abs(row - i);
                        if(j + x < n){
                            ok[j + x] = true;
                        }
                        if(j - x >= 0){
                            ok[j - x] = true;
                        }
                    }
                }
            }
            for(int j = 0; j < n; ++j){
                if(!ok[j]){
                    cur[row][j] = true;
                    helper(cur, n, row + 1, ans);
                    cur[row][j] = false;
                }
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        boolean cur[][] = new boolean[n][n];
        List<List<String>> ans = new ArrayList<List<String>>();
        helper(cur, n, 0, ans);
        return ans;
    }
}
