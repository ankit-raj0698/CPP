//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    struct Item{
        int value;
        int weight;
        double ratio;
    };
    static bool comparator(Item &a, Item &b){
        return a.ratio > b.ratio;
    }
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        // Your code here
        int n = values.size();
        vector<Item> arr(n);
        for(int i = 0; i < n; i++){
            arr[i].value = values[i];
            arr[i].weight = weights[i];
            arr[i].ratio = values[i]/(weights[i] * 1.0);
        }
        
        sort(arr.begin(), arr.end(), comparator);
        double totalProfit = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i].weight <= w){
                totalProfit += arr[i].value;
                w = w - arr[i].weight;
            }
            else {
                totalProfit += arr[i].value * w/(arr[i].weight * 1.0);
                break;
            }
        }
        return totalProfit;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends