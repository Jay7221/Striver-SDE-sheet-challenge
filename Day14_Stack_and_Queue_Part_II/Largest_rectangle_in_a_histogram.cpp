#include<bits/stdc++.h>
using namespace std;
int largestRectangle(vector < int > & heights) {
    int n = heights.size();
    vector<int> l(n, -1), r(n, n);
    int ans = 0;
    stack<int> st;
    for(int i = 0; i < n; ++i){
        while((st.size() > 0) && (heights[st.top()] >= heights[i])){
            st.pop();
        }
        if(st.size()){
            l[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i = n - 1; i >= 0; --i){
        while((st.size() > 0) && (heights[st.top()] >= heights[i])){
            st.pop();
        }
        if(st.size()){
            r[i] = st.top();
        }
        st.push(i);
    }
    for(int i = 0; i < n; ++i){
        ans = max(ans, heights[i] * (r[i] - l[i] - 1));
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        cout << largestRectangle(arr) << '\n';
    }
}
