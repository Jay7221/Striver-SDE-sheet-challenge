#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int add(int a, int b){
    return ((a + b) % MOD);
}
int sub(int a, int b){
    return (((a - b) % MOD + MOD) % MOD);
}
int mult(int a, int b){
    return ((a * 1ll * b) % MOD);
}
int power(int a, int p){
    int res = 1;
    while(p > 0){
        if(p & 1){
            res = mult(res, a);
        }
        a = mult(a, a);
        p >>= 1;
    }
    return res;
}
int divide(int a, int b){
    return mult(a, power(b, MOD - 2));
}
vector<int> stringMatch(string text, string pattern) {
    vector<int> ans;
    int k = pattern.size();
    int n = text.size();
    vector<int> hash(n);
    for(int i = 0; i < n; ++i){
        hash[i] = text[i] - 'a';
        if(i > 0){
            hash[i] += mult(hash[i - 1], 26);
        }
    }
    int req = 0;
    for(char ch : pattern){
        req = add(ch - 'a', mult(26, req));
    }
    for(int i = k - 1; i < n; ++i){
        int h = hash[i];
        if(i > k - 1){
            h = sub(h, mult(hash[i - k], power(26, k)));
        }
        if(h == req){
            ans.push_back(i - k + 1 + 1);
        }
    }
    return ans;
}
int main(){
    string s, p;
    cin >> s >> p;
    vector<int> v = stringMatch(s, p);
    cout << v.size() << '\n';
    for(int ind : v){
        cout << ind << ' ' ;
    }
    cout << '\n';
    return 0;
}
