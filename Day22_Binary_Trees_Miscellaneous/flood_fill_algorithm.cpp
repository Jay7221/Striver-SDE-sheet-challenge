#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if(image[x][y] == newColor){
            continue;
        }

        auto check = [&](int x, int y){
            return ((x >= 0) && (x < image.size()) && (y >= 0) && (y < image[0].size()));
        };
        for(int dx = -1; dx < 2; ++dx){
            for(int dy = -1; dy < 2; ++dy){
                if(abs(dx) + abs(dy) != 1){
                    continue;
                }
                if(!check(x + dx, y + dy)){
                    continue;
                }
                if(image[x + dx][y + dy] == image[x][y]){
                    q.push({x + dx, y + dy});
                }
            }
        }
        image[x][y] = newColor;
    }
    return image;
}
