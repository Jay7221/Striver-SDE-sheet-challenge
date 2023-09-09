#include <algorithm>

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    Kthlargest(int k, vector<int> &arr) {
        this -> k = k;
        for(int elem : arr){
            pq.push(elem);
        }
        while(pq.size() > k){
            pq.pop();
        }
    }

    int add(int num) {
        pq.push(num);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }

};
