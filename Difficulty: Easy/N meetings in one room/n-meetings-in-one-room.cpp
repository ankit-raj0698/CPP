//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    struct data{
        int start, end, pos;
    };
    
    static bool comparator(data &a, data &b){
        return a.end < b.end;
    }
    
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        int n = start.size();
        data arr[n];
        for(int i = 0; i < n; i++){
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }
        
        // sort on end time
        sort(arr, arr + n, comparator);
        
        // compare start time of one process with freetime of slot
        int count = 1, freetime = arr[0].end;
        for(int i = 1; i < n; i++){
            if(arr[i].start > freetime){
                count++;
                freetime = arr[i].end;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends