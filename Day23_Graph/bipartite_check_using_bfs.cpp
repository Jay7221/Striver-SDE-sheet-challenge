bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<int> color(n, -1);
	bool isBirpatite = true;
	for(int i = 0; (i < n) && isBirpatite; ++i){
		if(color[i] == -1){
			color[i] = 0;
		}
		for(int j = 0; j < n; ++j){
			if(edges[i][j] && (color[i] == color[j])){
				isBirpatite = false;
			}
			else if(edges[i][j]){
				color[j] = 1 - color[i];
			}
		}
	}
	return isBirpatite;
}
