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
 
vector<int> stringMatch(string text, string pattern) {
	int n = text.size();
	int m = pattern.size();
	vector<int> lps(m);
	int len = 0;
	for(int i = 1; i < m; ++i){
		while((len > 0) && pattern[i] != pattern[len]){
			len = lps[len - 1];
		}
		if(pattern[i] == pattern[len]){
			++len;
			lps[i] = len;
		}
	}
	int i = 0, j = 0;
	vector<int> ans;
	while(i < n){
		if(j == m){
			ans.push_back(i - m);
			j = lps[j - 1];
		}else{
			if(text[i] == pattern[j]){
				++i, ++j;
			}else{
				if(j > 0){
					j = lps[j - 1];
				}else{
					++i;
				}
			}
		}
	}
    if(j == m){
        ans.push_back(i - m);
    }
	return ans;
}
int main(){
    string s, p;
    cin >> s >> p;
    for(int elem : stringMatch(s, p)){
        cout << (elem + 1) << ' ';
    }
    cout << '\n';
}
