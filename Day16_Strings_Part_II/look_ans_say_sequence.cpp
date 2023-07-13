string next(string s){
    int f = 0;
    string ans;
    char cur = s.front();
    for(char ch : s){
        if(cur == ch){
            ++f;
        }else{
            ans.push_back(f + '0');
            ans.push_back(cur);
            cur = ch;
            f = 1;
        }
    }
    ans.push_back(f + '0');
    ans.push_back(cur);
    return ans;
}
string lookAndSaySequence(int n) 
{
    string s = "1";
    for(int i = 0; i < n - 1; ++i){
        s = next(s);
    }
    return s;
}
