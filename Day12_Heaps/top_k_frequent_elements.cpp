class Solution {
public:

    int qsort(vector<pair<int, int>> &v, int l, int r){
        int ind = l;
        int val = v[ind].second;
        for(int i = l + 1; i <= r; ++i){
            if(v[i].second > val){
                swap(v[i], v[ind]);
                ++ind;
                swap(v[i], v[ind]);
            }
        }
        return ind;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        map<int, int> freq;
        for(int elem : nums){
            ++freq[elem];
        }
        for(auto [u, f] : freq){
            v.push_back({u, f});
        }
        int n = v.size();
        auto debug = [&](){
for(auto [u, f] : v){
            cout << f << ' ' ;
        }
        cout << '\n';
        
        };
        int l = 0, r =  n - 1;
        while(l < r){
            int ind = qsort(v, l, r);
            if(ind > (k - 1)){
                r = ind - 1;
            }else if(ind < (k - 1)){
                l = ind + 1;
            }else{
                break;
            }
        }
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
