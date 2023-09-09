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
    for(int i = 0; (i < n) && !cyclePresent; ++i){
        if(vis[i]){
            continue;
        }
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(v != par[u]){
                    if(vis[v]){
                        cyclePresent = true;
                        break;
                    }
                    else{
                        q.push(v);
                        par[v] = u;
                        vis[v] = true;
                    }
                }
            }
            cout << '\n';
        }
    }
    

    if(cyclePresent){
        return "Yes";
    }
    else{
        return "No";
    }
}

