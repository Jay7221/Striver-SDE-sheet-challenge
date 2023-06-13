class Solution {
    boolean fill(int[][] board, int row, int col){
        if(row == 9){
            return true;
        }
        if(col == 9){
            return fill(board, row + 1, 0);
        }
        if(board[row][col] != 0){
            return fill(board, row, col + 1);
        }
        boolean vis[] = new boolean[10];
        for(int i = 0; i < 9; ++i){
            vis[board[i][col]] = true;
            vis[board[row][i]] = true;
        }
        int l = (row - (row % 3)), r = (col - (col % 3));
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                vis[board[i + l][j + r]] = true;
            }
        }
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 1; i <= 9; ++i){
            if(!vis[i]){
                list.add(i);
            }
        }
        for(int i = 1; i <= 9; ++i){
            if(!vis[i]){
                board[row][col] = i;
                if(fill(board, row, col + 1)){
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
    public void solveSudoku(char[][] board) {
        int n = board.length;
        int arr[][] = new int[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] != '.'){
                    arr[i][j] = board[i][j] - '0';
                }
            }
        }
        fill(arr, 0, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] = (char)(arr[i][j] + '0');
            }
        }
    }
}
