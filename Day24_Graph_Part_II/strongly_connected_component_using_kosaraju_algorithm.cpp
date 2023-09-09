#include<bits/stdc++.h>
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
    }

    function<void(int)> dfs, euler;
    
    vector<int> order;
    vector<bool> vis(n);
    euler = [&](int u){
        vis[u] = true;
        for(int v : adj[u]){
            if(!vis[v]){
                euler(v);
            }
        }
        order.push_back(u);
    };
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            euler(i);
        }
    }
    vis.assign(n, false);

    vector<int> comp;
    dfs = [&](int u){
        vis[u] = true;
        comp.push_back(u);
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    };
    reverse(order.begin(), order.end());
    adj.clear();
    adj.assign(n, vector<int>());
    for(auto e : edges){
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> ans;
    for(int i : order){
        if(!vis[i]){
            dfs(i);
            ans.push_back(comp);
            comp.clear();
        }
    }
    return ans;
}
