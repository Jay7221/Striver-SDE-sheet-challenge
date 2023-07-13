#include <bits/stdc++.h> 
using namespace std;
int cmp(string a, string b){
    if(a.size() > b.size()){
        return 1;
    }
    if(a.size() < b.size()){
        return -1;
    }
    if(a > b){
        return 1;
    }
    if(a < b){
        cerr << "! " << a << ' ' << b << '\n';
        return -1;
    }
    return 0;
}
int compareVersions(string a, string b) 
{
    int la = 0, lb = 0;
    while((la < a.size()) || (lb < b.size())){
        string aa = "0", bb = "0";
        if(la < a.size()){
            int sz = 1;
            while((la + sz) < a.size() && (a[la + sz] != '.')){
                ++sz;
            }
            aa = a.substr(la, sz);
            la = la + sz + 1;
        }
        if(lb < b.size()){
            int sz = 1;
            while((lb + sz) < b.size() && (b[lb + sz] != '.')){
                ++sz;
            }
            bb = b.substr(lb, sz);
            lb = lb + sz + 1;
        }
        int c = cmp(aa, bb);
        if(c != 0){
            return c;
        }
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << compareVersions(a, b) << '\n';
    }
}
