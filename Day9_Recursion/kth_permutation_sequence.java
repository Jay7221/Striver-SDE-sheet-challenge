class Solution {
    public String getPermutation(int n, int k) {
        int arr[] = new int[n];
        --k;
        for(int i = 0; i < n; ++i){
            arr[i] = i + 1;
        }
        int fact[] = new int[n];
        fact[0] = 1;
        for(int i = 1; i < n; ++i){
            fact[i] = i * fact[i - 1];
        }
        for(int i = 0; i < n; ++i){
            int num = fact[n - 1 - i];
            int p = k / num;
            k %= num;
            int cur = arr[i];
            arr[i] = arr[i + p];
            for(int j = 1; j <= p; ++j){
                int tmp = cur;
                cur = arr[i + j];
                arr[i + j] = tmp;
            }
        }
        StringBuilder ans = new StringBuilder();
        for(int elem : arr){
            ans.append(elem);
        }
        return ans.toString();
    }
}
