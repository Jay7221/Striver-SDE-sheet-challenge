#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int maxProd, minProd, result;
	maxProd = minProd = result = arr[0];
	for(int i = 1; i < n; ++i){
		int newMaxProd, newMinProd;
		newMaxProd = max({arr[i], maxProd * arr[i], minProd * arr[i]});
		newMinProd = min({arr[i], maxProd * arr[i], minProd * arr[i]});
		maxProd = newMaxProd;
		minProd = newMinProd;
		result = max(result, maxProd);
	}
	return result;
}
