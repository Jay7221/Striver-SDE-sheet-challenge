//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job a, Job b){
        return a.dead < b.dead;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compare);
        int numJobs = 0, profit = 0;
        
        multiset<int> m;
        for(int i = 0; i < n; ++i){
            int d = arr[i].dead, p = arr[i].profit;
            if(m.size() < d){
                m.insert(p);
            }else{
                if(p > (*m.begin())){
                    m.erase(m.begin());
                    m.insert(p);
                }
            }
        }
        numJobs = m.size();
        for(int p : m){
            profit += p;
        }
        vector<int> ans;
        ans.push_back(numJobs);
        ans.push_back(profit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
