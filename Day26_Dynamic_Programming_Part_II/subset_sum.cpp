#include <bits/stdc++.h> 
const int MAX = 2e3 + 7;
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    bitset<MAX> dp;
    dp[0] = true;
    for(int elem : arr){
        dp |= (dp << elem);
    }
    return dp[k];
}
