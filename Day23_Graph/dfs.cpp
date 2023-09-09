vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    int n = V;
    vector<vector<int>> adj(n);
    for(auto e : edges){
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n);
    function<void(int)> dfs;
    vector<int> component;
    dfs = [&](int u){
        vis[u] = true;
        component.push_back(u);
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    };
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i);
            ans.push_back(component);
            component.clear();
        }
    }
    for(auto &v : ans){
        sort(v.begin(), v.end());
    }
    return ans;
}
