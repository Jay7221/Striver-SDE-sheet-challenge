string reverseString(string &s){
	string curWord;
	vector<string> words;
	s.push_back(' ');
	for(char ch : s){
		if(ch == ' '){
			if(!curWord.empty()){
				words.push_back(curWord);
				curWord.clear();
			}
		}else{
			curWord.push_back(ch);
		}
	}
	reverse(words.begin(), words.end());
	string ans;
	for(string word : words){
		ans += word;
		ans.push_back(' ');
	}
	if(!ans.empty()){
		ans.pop_back();
	}
	return ans;
}
