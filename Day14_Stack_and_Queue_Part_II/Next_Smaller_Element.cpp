void immediateSmaller(vector<int>& a)
{
	int n = a.size();
	int prev = a[n - 1];
	a[n - 1] = -1;
	for(int i = n - 2; i >= 0; --i){
		int cur = a[i];
		if(prev < a[i]){
			a[i] = prev;
		}else{
			a[i] = -1;
		}
		prev = cur;
	}
}

