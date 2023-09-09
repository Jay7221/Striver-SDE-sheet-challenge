#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<int> dp = rack;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(rack[i] > rack[j]){
				dp[i] = max(dp[i], dp[j] + rack[i]);
			}
		}
	}
	int ans = 0;
	for(int elem : dp){
		ans = max(ans, elem);
	}
	return ans;
}
