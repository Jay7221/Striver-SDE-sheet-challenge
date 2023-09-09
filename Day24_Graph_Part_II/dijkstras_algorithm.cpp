#include <bits/stdc++.h> 
const long long INF = INT_MAX;
vector<int> dijkstra(vector<vector<int>> &vec, int n, int m, int source) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto e : vec){
        int u, v, w;
        u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> d(n, INF);
    d[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; ++i){
        pq.push({d[i], i});
    }
    while(!pq.empty()){
        int u, du;
        tie(du, u) = pq.top();
        pq.pop();
        if(du > d[u]){
            continue;
        }
        if(d[u] == INF){
            break;
        }
        for(auto nei : adj[u]){
            int v, w;
            tie(v, w) = nei;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}
