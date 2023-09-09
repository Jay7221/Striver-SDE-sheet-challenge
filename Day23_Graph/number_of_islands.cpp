#include<bits/stdc++.h>
int getTotalIslands(int** arr, int n, int m)
{
   int ans = 0;
   auto check = [&](int x, int y){
      return ((x >= 0) && (y >= 0) && (x < n) && (y < m) && (arr[x][y] == 1));
   };
   for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
         if(arr[i][j] == 1){
            ++ans;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
               int x, y;
               tie(x, y) = q.front();
               q.pop();
               if(arr[x][y] == 0){
                  continue;
               }
               arr[x][y] = 0;
               for(int dx = -1; dx < 2; ++dx){
                  for(int dy = -1; dy < 2; ++dy){
                     if(abs(dx) + abs(dy) > 0){
                        int xx = x + dx, yy = y + dy;
                        if(check(xx, yy)){
                           q.push({xx, yy});
                        }
                     }
                  }
               }
            }
         }
      }
   }
   return ans;
}

