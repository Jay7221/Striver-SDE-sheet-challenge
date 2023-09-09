string longestCommonPrefix(vector<string> &arr, int n)
{
    string prefix;
    for(int i = 0; i < arr[0].size(); ++i){
        char cur = arr[0][i];
        bool flag = true;
        for(string s : arr){
            if(s.size() <= i){
                flag = false;
                break;
            }
            if(s[i] != cur){
                flag = false;
                break;
            }
        }
        if(flag){
            prefix.push_back(cur);
        }
        else{
            break;
        }
    }
    return prefix;
}



