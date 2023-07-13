#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 
vector<int> getZ(string s){
    int n = s.size();
    vector<int> z(n);
    int l = 1;
    for(int i = 1; i < n; ++i){
        z[i] = z[i - l];
        while((i + z[i] < n) && (s[i + z[i]] == s[z[i]])){
            ++z[i];
        }
        if((i + z[i]) >= (l + z[l])){
            l = i;
        }
    }
    cerr << s << '\n' << z << "\n-------------------\n";
    return z;
}
vector<int> search(string s, string pattern) {
    vector<int> ans;
    string zs = pattern + "$" + s;
    vector<int> z = getZ(zs);
    int p = pattern.size(), n = s.size();
    for(int i = p + 1; i < (n + p + 1); ++i){
        if(z[i] == p){
            ans.push_back(i - (p + 1) + 1);
        }
    }
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    string s, p;
    cin >> s >> p;
    for(int elem : search(s, p)){
        cout << (elem + 1) << ' ';
    }
    cout << '\n';
}
