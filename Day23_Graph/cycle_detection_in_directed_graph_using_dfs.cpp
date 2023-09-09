#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n);
    for(auto e : edges){
        int u, v;
        tie(u, v) = e;
        --u, --v;
        adj[u].push_back(v);
    }
    bool cyclePresent = false;
    vector<int> vis(n);
    function<void(int)> dfs;
    dfs = [&](int u){
        vis[u] = 2;
        for(int v : adj[u]){
          if(!vis[v]){
            dfs(v);
          }else if(vis[v] == 2){
            cyclePresent = true;
          }
        }
        vis[u] = 1;
    };
    for(int i = 0; i < n; ++i){
      if(!vis[i]){
        dfs(i);
      }
    }
    

    return cyclePresent;
}


