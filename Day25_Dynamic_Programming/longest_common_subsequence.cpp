int lcs(string s, string t)
{
	int n = s.size(), m = t.size();
	int dp[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			dp[i][j] = (s[i] == t[j]);
			if(i > 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			if(j > 0){
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			}
			if((i > 0) && (j > 0)){
				dp[i][j] = max(dp[i][j], (s[i] == t[j]) + dp[i - 1][j - 1]);
			}
		}
	}
	return dp[n - 1][m - 1];
}
