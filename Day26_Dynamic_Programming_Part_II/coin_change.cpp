long countWaysToMakeChange(int *denominations, int n, int value)
{
    long dp[value + 1];
    for(int i = 0; i < value + 1; ++i){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int val = denominations[i]; val <= value; ++val){
            dp[val] += dp[val - denominations[i]];
        }
    }
    return dp[value];
}
