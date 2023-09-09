#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &dp) {
    int n = dp.size();
    int m = dp[0].size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if((i > 0) && (j > 0)){
                dp[i][j] += min(dp[i][j - 1], dp[i - 1][j]);
            }
            else if(i > 0){
                dp[i][j] += dp[i - 1][j];
            }
            else if(j > 0){
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    return dp[n - 1][m - 1];
}
