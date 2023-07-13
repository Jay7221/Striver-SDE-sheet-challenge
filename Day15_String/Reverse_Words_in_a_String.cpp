string reverseString(string &s){
	while(!s.empty() && (s.back() == ' ')){
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	while(!s.empty() && (s.back() == ' ')){
		s.pop_back();
	}
	int ind = 0;
	for(int i = 0; i < s.size(); ++i){
		if((i > 0) && (s[i] == s[i - 1]) && (s[i] == ' ')){
			continue;
		}
		s[ind] = s[i];
		++ind;
	}
	int n = ind;
	s.resize(n);
	int l = 0;
	for(int r = 0; r < n; ++r){
		if(s[r] == ' '){
			reverse(s.begin() + l, s.begin() + r);
			l = r + 1;
		}
	}
	reverse(s.begin() + l, s.begin() + n);
	return s;
}
