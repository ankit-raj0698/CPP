//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        typedef pair<int,int> t;
        priority_queue<t,vector<t>,greater<t>> pq;
        vector<bool> visited(V,false);
        int sum = 0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(!visited[node]){
                visited[node] = true;
                sum += d;
                
                for(auto &vec: adj[node]){
                    int neighbour = vec[0];
                    int neighbour_wt = vec[1];
                    
                    if(!visited[neighbour])
                        pq.push({neighbour_wt,neighbour});
                }
                
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends