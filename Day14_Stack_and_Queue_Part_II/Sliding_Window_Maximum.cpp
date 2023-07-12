#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int n, int k){
    vector<int> ans;
    deque<int> d;
    for(int i = 0; i < k; ++i){
        while((d.size() > 0) && (arr[d.back()] <= arr[i])){
            d.pop_back();
        }
        d.push_back(i);
    }
    ans.push_back(d.front());
    for(int i = k; i < n; ++i){
        if(d.front() == i - k){
            d.pop_front();
        }
        while((d.size() > 0) && (arr[d.back()] <= arr[i])){
            d.pop_back();
        }
        d.push_back(i);
        ans.push_back(d.front());
    }
    for(int &elem : ans){
        elem = arr[elem];
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        for(int elem : maxSlidingWindow(arr, n, k)){
            cout << elem << ' ';
        }
        cout << '\n';
    }
    return 0;
}
