#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cyclePresent = false;
    vector<int> par(n, -1);
    vector<bool> vis(n);
    function<void(int)> dfs;
    dfs = [&](int u){
        vis[u] = true;
        for(int v : adj[u]){
            if(v == par[u]){
                continue;
            }
            if(!vis[v]){
                par[v] = u;
                dfs(v);
            }
            else{
                cyclePresent = true;
                return;
            }
        }
    };
    for(int i = 0; (i < n) && !cyclePresent; ++i){
        if(vis[i]){
            continue;
        }
        dfs(i);
    }
    

    if(cyclePresent){
        return "Yes";
    }
    else{
        return "No";
    }
}

