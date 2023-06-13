//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int tc = scan.nextInt();

        while (tc-- > 0) {
            int N = scan.nextInt();
            int M = scan.nextInt();
            int E = scan.nextInt();

            boolean graph[][] = new boolean[N][N];

            for (int i = 0; i < E; i++) {
                int u = scan.nextInt() - 1;
                int v = scan.nextInt() - 1;
                graph[u][v] = true;
                graph[v][u] = true;
            }

            System.out.println(new solve().graphColoring(graph, M, N) ? 1 : 0);
        }
    }
}

// } Driver Code Ends


class solve {
    // Function to determine if graph can be coloured with at most M colours
    // such
    // that no two adjacent vertices of graph are coloured with same colour.
    boolean graph[][];
    int n;
    int m;
    int color[];
    public boolean graphColoring(boolean graph[][], int m, int n) {
        this.n = n;
        this.m = m;
        this.graph = graph;
        this.color = new int[n];
        if(fill(0)){
            return true;
        }else{
            return false;
        }
    }
    boolean fill(int node){
        if(node == n){
            return true;
        }
        boolean vis[] = new boolean[m + 1];
        for(int i = 0; i < n; ++i){
            if(graph[node][i] || graph[i][node]){
                vis[color[i]] = true;
            }
        }
        for(int i = 1; i <= m; ++i){
            if(!vis[i]){
                color[node] = i;
                if(fill(node + 1)){
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
}
