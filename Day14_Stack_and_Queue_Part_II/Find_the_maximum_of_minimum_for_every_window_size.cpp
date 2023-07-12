#include <bits/stdc++.h> 
const int INF = 1e9 + 7;
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> l(n, -1), r(n, n);
    stack<int> st;
    for(int i = 0; i < n; ++i){
        while(!st.empty() && (a[st.top()] >= a[i])){
            st.pop();
        }
        if(!st.empty()){
            l[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i = n - 1; i >= 0; --i){
        while(!st.empty() && (a[st.top()] >= a[i])){
            st.pop();
        }
        if(!st.empty()){
            r[i] = st.top();
        }
        st.push(i);
    }
    vector<int> ans(n, -INF);
    for(int i = 0; i < n; ++i){
        int sz = r[i] - l[i] - 1;
        --sz;
        sz = min(sz, n - 1);
        ans[sz] = max(ans[sz], a[i]);
    }
    for(int i = n - 1; i > 0; --i){
        ans[i - 1] = max(ans[i - 1], ans[i]);
    }
    return ans;
}
