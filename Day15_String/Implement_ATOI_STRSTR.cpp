#include <bits/stdc++.h> 
int atoi(string str) {
    int ans = 0;
    for(char ch : str){
        if(('0' <= ch) && (ch <= '9')){
            ans = 10 * ans + (ch - '0');
        }
    }
    if(str.front() == '-'){
        ans = -ans;
    }
    return ans;
}
