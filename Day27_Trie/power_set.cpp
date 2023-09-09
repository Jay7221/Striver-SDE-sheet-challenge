#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> cur;
    function<void(int l)> dfs;
    dfs = [&](int ind){
        if(ind == v.size()){
            ans.push_back(cur);
            return;
        }
        dfs(ind + 1);
        cur.push_back(v[ind]);
        dfs(ind + 1);
        cur.pop_back();
    };
    dfs(0);
    return ans;
}
