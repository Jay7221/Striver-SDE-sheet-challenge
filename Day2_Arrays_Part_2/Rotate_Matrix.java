class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0; i < (n + 1) / 2; ++i){
            for(int j = 0; j < (n) / 2; ++j){
                int l, r, x, y, tmp;
                
                l = i;
                r = j;
                x = j;
                y = n - 1 - i;
                tmp = matrix[x][y];
                matrix[x][y] = matrix[l][r];
                matrix[l][r] = tmp;
                
                
                x = l;
                y = r;
                l = n - 1 - y;
                r = x;
                tmp = matrix[x][y];
                matrix[x][y] = matrix[l][r];
                matrix[l][r] = tmp;
                
                x = l;
                y = r;
                l = n - 1 - y;
                r = x;
                tmp = matrix[x][y];
                matrix[x][y] = matrix[l][r];
                matrix[l][r] = tmp;
            }
        }
    }
}
