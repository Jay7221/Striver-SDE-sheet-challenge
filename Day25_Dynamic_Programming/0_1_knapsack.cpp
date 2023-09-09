int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<int> profit(w + 1);
	for(int i = 0; i < n; ++i){
		for(int weight = w; weight >= weights[i]; --weight){
			profit[weight] = max(profit[weight], profit[weight - weights[i]] + values[i]);
		}
	}
	int ans = 0;
	for(int elem : profit){
		ans = max(ans, elem);
	}
	return ans;
}
