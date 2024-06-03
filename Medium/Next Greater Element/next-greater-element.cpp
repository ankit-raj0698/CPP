//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> st;
        
        // traverse the array from right to left
        for(int i = n - 1; i >= 0; i--){
            //when stack is empty push -1
            if(st.size() == 0){
                ans.push_back(-1);
            }
            // when encountered next greater element push to stack
            else if(st.top() > arr[i]){
                ans.push_back(st.top());
            }
            //when stack's top element is less than current element pop from stack
            else if(st.size() > 0 && st.top() <= arr[i]){
                while(st.size() > 0 && st.top() <= arr[i]){
                    st.pop();
                }
                // at the end of popping check and push the respective ans 
                if(st.size() == 0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top());
                }
            }
            // at the end push the current element
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends