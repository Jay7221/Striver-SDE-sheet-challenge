#include<bits/stdc++.h>
using namespace std;
class LFUCache
{
public:
    map<int, int> freq;
    map<int, int> lastUse;
    map<int, int> memory;
    set<tuple<int, int, int>> st;
    int curTime;
    int capacity;
    LFUCache(int capacity) : capacity(capacity)
    {
        curTime = 1;
    }

    int get(int key)
    {
        if(lastUse[key] == 0){
            return -1;
        }
        st.erase({freq[key], lastUse[key], key});
        ++freq[key];
        lastUse[key] = curTime++;
        st.insert({freq[key], lastUse[key], key});
        return memory[key];
    }

    void put(int key, int value)
    {
        st.erase({freq[key], lastUse[key], key});
        ++freq[key];
        lastUse[key] = curTime++;
        if(st.size() == capacity){
            int k, _, __;
            tie(__, _, k) = *st.begin();
            st.erase(st.begin());
            freq.erase(k);
            lastUse.erase(k);
            memory.erase(k);
        }
        st.insert({freq[key], lastUse[key], key});
        memory[key] = value;
    }
};
int main(){
    int q;
    cin >> q;
    int capacity;
    cin >> capacity;
    LFUCache l(capacity);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int key;
            cin >> key;
            cout << l.get(key) << ' ';
        }else{
            int key, value;
            cin >> key >> value;
            l.put(key, value);
        }
    }
    return 0;
}
