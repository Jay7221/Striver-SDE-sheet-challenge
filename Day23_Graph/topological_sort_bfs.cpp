#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    int n = v;
    vector<vector<int>> adj(n);
    vector<int> in(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        ++in[v];
    }
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> order;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(int v : adj[u]){
            --in[v];
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    return order;
}
