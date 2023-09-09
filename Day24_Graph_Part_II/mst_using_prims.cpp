#include <bits/stdc++.h>
#define ll long long
#define edge pair<pair<int, int>, int>
const ll INF = 1e15 + 7;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    priority_queue<pair<ll, edge>, vector<pair<ll, edge>>, greater<pair<ll, edge>>> pq;
    vector<edge> ans;
    vector<bool> vis(n + 1);
    pq.push({0, {{-1, 1}, 0}});
    vector<vector<edge>> adj(n + 1);
    for(edge e : g){
        adj[e.first.first].push_back(e);
        adj[e.first.second].push_back(e);
    }
    while(!pq.empty()){
        ll du;
        edge e;
        tie(du, e) = pq.top();
        pq.pop();
        int p  = e.first.first;
        int u = e.first.second;
        if(vis[u]){
            continue;
        }
        vis[u] = true;
        if(p != -1){
            ans.push_back(e);
        }
        for(edge e : adj[u]){
            int v = e.first.second;
            if(v == u){
                v = e.first.first;
            }
            int w = e.second;
            if(!vis[v]){
                pq.push({w, {{u, v}, w}});
            }
        }
    }
    return ans;
}
