#include<bits/stdc++.h>
vector<int> findStockSpans(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n, 1);
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < n; ++i){
        while((st.size() > 1) && (prices[st.top()] < prices[i])){
            st.pop();
        }
        span[i] = (i - st.top());
        st.push(i);
    }
    return span;
}
