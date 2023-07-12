#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int, pair<int, int>>> q;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 2){
                q.push({0, {i, j}});
            }
        }
    }
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()){
        int time, x, y;
        pair<int, int> coord;
        tie(time, coord) = q.front();
        tie(x, y) = coord;
        ans = time;
        q.pop();
        for(pair<int, int> dd : d){
            int dx, dy;
            tie(dx, dy) = dd;
            int xx = x + dx, yy = y + dy;
            if((xx >= 0) && (yy >= 0) && (xx < n) && (yy < m) && (grid[xx][yy] == 1)){
                grid[xx][yy] = 2;
                q.push({time + 1, {xx, yy}});
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 1){
                return -1;
            }
        }
    }
    return ans;
}
