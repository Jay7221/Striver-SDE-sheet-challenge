#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	for(int i = 0; i < n; ++i){
		if(!left.empty() && (arr[i] < left.top())){
			left.push(arr[i]);
		}
		else{
			right.push(arr[i]);
		}
		while(left.size() > right.size() + 1){
			right.push(left.top());
			left.pop();
		}
		while(right.size() > left.size()){
			left.push(right.top());
			right.pop();
		}
		int median = left.top();
		if(right.size() == left.size()){
			median = (median + right.top()) / 2;
		}
		ans.push_back(median);
	}
	return ans;
}

