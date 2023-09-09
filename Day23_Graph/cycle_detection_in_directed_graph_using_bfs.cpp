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
    function<void(int)> bfs;
    bfs = [&](int u){
      queue<int> q;
      vector<int> v;
      q.push(u);
      vis[u] = 2;
      while(!q.empty()){
        int u = q.front();
        v.push_back(u);
        q.pop();
        for(int v : adj[u]){
          if(!vis[v]){
            q.push(v);
            vis[v] = 2;
          }
          else if(vis[v] == 2){
            cyclePresent = true;
            break;
          }
        }
      }
      for(int ind : v){
        vis[ind] = 1;
      }
    };

    for(int i = 0; (i < n) && !cyclePresent; ++i){
      if(!vis[i]){
        bfs(i);
      }
    }
    
    return cyclePresent;
}


