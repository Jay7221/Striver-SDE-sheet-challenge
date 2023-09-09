vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    queue<int> q;
    vector<bool> vis(n);
    q.push(0);
    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        q.pop();
        vis[u] = true;
        for(int v : adj[u]){
            if(vis[v]){
                continue;
            }
            q.push(v);
            vis[v] = true;
        }
    }
    return ans;
}
