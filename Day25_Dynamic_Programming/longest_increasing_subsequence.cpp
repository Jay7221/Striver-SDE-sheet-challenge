#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lcs = {arr[0]};
    for(int i = 1; i < n; ++i){
        if(arr[i] > lcs.back()){
            lcs.push_back(arr[i]);
        }
        else{
            int ind = (lower_bound(lcs.begin(), lcs.end(), arr[i]) - lcs.begin());
            lcs[ind] = arr[i];
        }
    }
    return lcs.size();
}

