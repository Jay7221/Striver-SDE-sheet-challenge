#include<bits/stdc++.h>
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int numJobs = 0, profit = 0;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i){
        v[i] = {jobs[i][1], jobs[i][2]};
    }
    sort(v.rbegin(), v.rend());
    priority_queue<int> pq;
    int ind = 0;
    for(int day = n; day >= 1; --day){
        while((ind < n) && (v[ind].first >= day)){
            pq.push(v[ind].second);
            ++ind;
        }
        if(!pq.empty()){
            ++numJobs;
            profit += pq.top();
            pq.pop();
        }
    }
    vector<int> ans = {numJobs, profit};
    return ans;
}
