const int INF = 1e9;
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int dist[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    for(auto e : edges){
        int u = e[0], v = e[1], w = e[2];
        --u, --v;
        dist[u][v] = min(dist[u][v], w);
    }
    for(int k = 0; k < n; ++k){
        for(int u = 0; u < n; ++u){
            for(int v = 0; v < n; ++v){
                if(max(dist[u][k], dist[k][v]) != INF){
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }
    --src, --dest;
    return dist[src][dest];
}
