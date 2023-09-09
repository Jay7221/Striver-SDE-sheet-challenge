#include<bits/stdc++.h>
using namespace std;
vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    vector<string> ans;
    string cur;

    function<void(int)> generate;

    generate = [&](int ind){
        if(ind == s.size()){
            ans.push_back(cur);
            return;
        }
        
        for(string word : dict){
            int len = word.size();
            if(ind + len > s.size()){
                continue;
            }
            if(s.substr(ind, len) != word){
                continue;
            }
            if(!cur.empty()){
                cur.push_back(' ');
            }
            cur += word;
            generate(ind + len);
            for(int cnt = 0; cnt < len; ++cnt){
                cur.pop_back();
            }
            if(!cur.empty()){
                cur.pop_back();
            }
        }
    };
    
    generate(0);
    
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    string s;
    cin >> s;
    for(string sen : getAllValidSentences(s, v)){
        cout << sen << '\n';
    }
    return 0;
}
