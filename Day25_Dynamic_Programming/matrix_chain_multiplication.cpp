#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    int dp[N][N];
    for(int len = 1; len <= N; ++len){
        for(int i = 0; i < N + 1 - len; ++i){
            int j = i + len - 1;
            if(len <= 2){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9 + 7;
            for(int k = i + 1; k < j; ++k){
                dp[i][j] = min(dp[i][j], (arr[i] * arr[k] * arr[j]) + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][N - 1];
}
