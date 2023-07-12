#include<bits/stdc++.h>
class LRUCache
{
public:
    map<int, int> memory;
    map<int, int> prevUse;
    set<pair<int, int>> st;
    int curPointer;
    int capacity;
    LRUCache(int capacity) : capacity(capacity)
    {
        curPointer = 1;
    }

    int get(int key)
    {
        if(prevUse[key] == 0){
            return -1;
        }
        st.erase({prevUse[key], key});
        prevUse[key] = curPointer++;
        st.insert({prevUse[key], key});
        return memory[key];
    }

    void put(int key, int value)
    {
        if(prevUse[key] > 0){
            st.erase({prevUse[key], key});
            prevUse.erase(key);
            memory.erase(key);
        }
        if(st.size() == capacity){
            int leastRecentKey, _ ;
            tie(_, leastRecentKey) = *st.begin();
            st.erase(st.begin());
            memory.erase(leastRecentKey);
            prevUse.erase(leastRecentKey);
        }
        prevUse[key] = curPointer;
        st.insert({prevUse[key], key});
        memory[key] = value;
        ++curPointer;
    }
};

