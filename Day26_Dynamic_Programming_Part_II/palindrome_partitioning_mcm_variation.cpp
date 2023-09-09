int palindromePartitioning(string str)
{
    int n = str.size();
    auto isPal = [&](int l, int r){
        while(l < r){
            if(str[l] != str[r]){
                return false;
            }
            ++l;
            --r;
        }
        return true;
    };
    int dp[n];
    for(int i = 0; i < n; ++i){
        dp[i] = i;
        if(isPal(0, i)){
            dp[i] = 0;
        }
        else{
            for(int j = 1; j <= i; ++j){
                if(isPal(j, i)){
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }
    return dp[n - 1];
}

