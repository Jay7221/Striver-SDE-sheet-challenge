class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};

int kruskalMST(int n, vector<vector<int>> &edges)
{
	DSU dsu(n + 1);
	sort(edges.begin(), edges.end(),
	[](vector<int> v1, vector<int> v2){
		return (v1[2] < v2[2]);
	}
	);
	int ans = 0;
	for(vector<int> e : edges){
		int u = e[0], v = e[1], w = e[2];
		if(dsu.get_par(u) != dsu.get_par(v)){
			dsu.merge(u, v);
			ans += w;
		}
	}
	return ans;
}
