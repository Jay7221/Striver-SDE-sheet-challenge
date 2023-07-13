#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    vector<int> freq(26);
    for(char ch : str1){
        ++freq[ch - 'a'];
    }
    for(char ch : str2){
        --freq[ch - 'a'];
    }
    for(int elem : freq){
        if(elem != 0){
            return false;
        }
    }
    return true;
}
