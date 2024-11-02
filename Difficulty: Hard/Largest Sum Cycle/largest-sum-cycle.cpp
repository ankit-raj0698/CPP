//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int ans;
  void cycle(vector<int> &Edge, int u, vector<int> &visited, vector<int> &inrecursion, vector<int> &path){
      visited[u] = 1;
      inrecursion[u] = 1;
      path.push_back(u);
      int v = Edge[u];
      if(v != -1){
          if(!visited[v]){
              cycle(Edge, v, visited, inrecursion, path);
          }
          else if(inrecursion[v] == 1){
              int sum = 0;
              for(int i = path.size() - 1; i >= 0; i--){
                  sum += path[i];
                  ans = max(ans, sum);
                  
                  if(path[i] == v)
                    break;
              }
          }
      }
      
      inrecursion[u] = 0;
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    vector<int> visited(N, 0);
    vector<int> inrecursion(N, 0);
    ans = -1;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            vector<int> path;
            cycle(Edge, i, visited, inrecursion, path);
        }
    }
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends