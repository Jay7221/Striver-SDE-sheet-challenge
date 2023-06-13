//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
    public static ArrayList<String> findPath(int[][] m, int n) {
        StringBuilder s = new StringBuilder();
        ArrayList<String> ans = new ArrayList<String>();
        if(m[0][0] == 1){
            fill(m, n, 0, 0, ans, s);
        }
        return ans;
    }
    static void fill(int m[][], int n, int i, int j, ArrayList<String> ans, StringBuilder s){
        // System.out.println(i + " " + j);
        if((i == n - 1) && (j == n - 1)){
            ans.add(s.toString());
        }else{
            m[i][j] = 0;
            if(i + 1 < n && m[i + 1][j] == 1){
                s.append('D');
                fill(m, n, i + 1, j, ans, s);
                s.setLength(s.length() - 1);
            }
            if(j - 1 >= 0 && m[i][j - 1] == 1){
                s.append('L');
                fill(m, n, i, j - 1, ans, s);
                s.setLength(s.length() - 1);
                
            }
            if(j + 1 < n && m[i][j + 1] == 1){
                s.append('R');
                fill(m, n, i, j + 1, ans, s);
                s.setLength(s.length() - 1);
                
            }
            if(i - 1 >= 0 && m[i - 1][j] == 1){
                s.append('U');
                fill(m, n, i - 1, j, ans, s);
                s.setLength(s.length() - 1);
            }
            m[i][j] = 1;
        }
    }
    
}

/*
0111
1110
1011
0011
*/
