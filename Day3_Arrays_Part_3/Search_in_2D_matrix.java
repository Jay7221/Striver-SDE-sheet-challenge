class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(matrix[mid][0] > target){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        int i = l;
        l = 0;
        r = m - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(matrix[i][mid] > target){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        int j = l;
        return (matrix[i][j] == target);
    }
}
