//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
    bool static comparator(Job a, Job b){
        return a.profit > b.profit;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n) {
        // your code here
        int maxDeadline = 0;
        // sort jobs acc to profit
        sort(jobs, jobs + n, comparator);
        
        for(int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, jobs[i].deadline);
        }
        
        vector<int> schedule(maxDeadline + 1, -1);
        
        int count = 0;
        int maxProfit = 0;
        
        for(int i = 0; i < n; i++){
            
            int job_id = jobs[i].id;
            int job_deadline = jobs[i].deadline;
            int job_profit = jobs[i].profit;
            
            for(int k = job_deadline; k >= 1; k--){
                
                if(schedule[k] == -1){
                    schedule[k] = job_id;
                    count++;
                    maxProfit += job_profit;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        
        return ans;
    }
};

//{ Driver Code Starts.
//    Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends