string commonPrefix(vector<string>& arr,int n){
	int l = arr.front().size();
	string ans;
	for(string s : arr){
		l = min(l, (int)s.size());
	}
	for(int i = 0; i < l; ++i){
		char ch = arr.front()[i];
		bool flag = true;
		for(string s : arr){
			if(s[i] != ch){
				flag = false;
				break;
			}
		}
		if(flag){
			ans.push_back(ch);
		}else{
			break;
		}
	}
	if(ans.empty()){
		ans = "-1";
	}
	return ans;
}
