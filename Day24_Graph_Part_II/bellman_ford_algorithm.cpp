#include <bits/stdc++.h> 
const int INF = 1000000000;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    --src, --dest;
    vector<int> dist(n, INF);
    dist[src] = 0;
    for(int i = 0; i < n - 1; ++i){
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            --u, --v;
            if(dist[u] == INF){
                continue;
            }
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    return dist[dest];
}
