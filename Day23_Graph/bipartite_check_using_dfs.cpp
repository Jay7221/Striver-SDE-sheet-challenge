#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<int> color(n, -1);
	bool isBirpatite = true;
	function<void(int)> dfs;
	dfs = [&](int u){
		for(int v = 0; v < n; ++v){
			if(edges[u][v]){
				if(color[u] == color[v]){
					isBirpatite = false;
					return;
				}
				if(color[v] == -1){
					color[v] = 1 - color[u];
					dfs(v);
				}
			}
		}
	};
	for(int i = 0; (i < n) && isBirpatite; ++i){
		if(color[i] == -1){
			color[i] = 0;
			dfs(i);
		}
	}
	return isBirpatite;
}
