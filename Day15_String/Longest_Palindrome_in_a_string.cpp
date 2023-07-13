string longestPalinSubstring(string str)
{
    int n = str.size();
    bool isPal[n][n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            isPal[i][j] = true;
        }
    }
    int x = 0, y = 0;
    for(int k = 1; k < n; ++k){
        for(int i = 0, j = k; j < n; ++i, ++j){
            isPal[i][j] = (isPal[i + 1][j - 1] && (str[i] == str[j]));
        }
    }
    for(int k = 1; k < n; ++k){
        for(int i = 0, j = k; j < n; ++i, ++j){
            if(isPal[i][j]){
                x = i, y = j;
                break;
            }
        }
    }
    return str.substr(x, y - x + 1);
}
