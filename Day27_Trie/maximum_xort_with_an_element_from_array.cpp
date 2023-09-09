#include<bits/stdc++.h>
struct Node{
    bool isEnd = false;
    Node *children[26];
};
void insert(int num, Node *root){
    for(int k = 30; k >= 0; --k){
        int ch = (1 & (num >> k));
        if(root -> children[ch] == NULL){
            root -> children[ch] = new Node();
        }
        root = root -> children[ch];
    }
}
int getMaxXor(int x, Node *root){
    int ans = 0;
    for(int k = 30; k >= 0; --k){
        int ch = (1 & (x >> k));
        ch = (1 - ch);
        if(root -> children[ch]){
            ans ^= (1 << k);
        }else{
            ch = (1 - ch);
        }
        root = root -> children[ch];
    }
    return ans;
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    Node *root = new Node();
    int n = arr.size();
	int i = 0;
	vector<tuple<int, int, int>> v;
	for(int i = 0; i < queries.size(); ++i){
		v.push_back((tuple<int, int, int>){queries[i][1], queries[i][0], i});
	}
	sort(v.begin(), v.end());
	sort(arr.begin(), arr.end());
	vector<int> ans(queries.size(), -1);
	for(auto elem : v){
		int ind, x, a;
		tie(a, x, ind) = elem;
		while((i < n) && (arr[i] <= a)){
			insert(arr[i], root);
			++i;
		}
		if(i > 0){
			ans[ind] = getMaxXor(x, root);
		}
	}
	return ans;
}
