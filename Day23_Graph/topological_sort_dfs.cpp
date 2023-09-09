#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    int n = v;
    vector<vector<int>> adj(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }
    vector<bool> vis(n);
    vector<int> order;
    function<void(int)> dfs;
    dfs = [&](int u){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
        order.push_back(u);
    };
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}
