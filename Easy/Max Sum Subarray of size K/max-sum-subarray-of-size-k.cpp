//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        /*int i=0;
        long maxSum=INT_MIN;
        long currSum=0;
        for(int j=0;j<N;j++){
            currSum+=Arr[j];
            if(j-i+1==K){
                maxSum=max(maxSum,currSum);
                currSum-=Arr[i];
                i++;
            }
        }
        return maxSum;*/
        
        int left=0,right=0;
        long maxSum=INT_MIN;
        long currSum=0;
        while(right<N){
            currSum+=Arr[right];
            if(right-left+1==K){
                maxSum=max(maxSum,currSum);
                currSum-=Arr[left];
                left++;
            }
            right++;
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends