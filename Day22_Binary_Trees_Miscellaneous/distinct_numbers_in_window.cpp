#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();
    map<int, int> freq;
    int numDistinct = 0;
    vector<int> ans;
    auto add = [&](int x){
        ++freq[x];
        numDistinct += (freq[x] == 1);
    };
    auto remove = [&](int x){
        --freq[x];
        numDistinct -= (freq[x] == 0);
    };
    for(int i = 0; i < k; ++i){
        add(arr[i]);
    }
    ans.push_back(numDistinct);
    for(int i = k; i < n; ++i){
      add(arr[i]);
      remove(arr[i - k]);
      ans.push_back(numDistinct);  
    }
    return ans;	
}

