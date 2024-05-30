//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &St){
        
        //base case
        if(St.size() == 1) return;
        
        int top = St.top();
        St.pop();
        
        Reverse(St);
        
        // take a temp  and push all the elements in it 
        stack<int> temp;
        while(!St.empty()){
            temp.push(St.top());
            St.pop();
        }
        
        St.push(top);
        
        while(!temp.empty()){
            St.push(temp.top());
            temp.pop();
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends