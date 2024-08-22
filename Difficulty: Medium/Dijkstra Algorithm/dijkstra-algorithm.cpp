//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        typedef pair<int,int> t;
        priority_queue<t,vector<t>,greater<t>> pq;
        
        vector<int> res(V,INT_MAX);
        
        res[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // find the adjacent nodes of u
            for(auto vec: adj[u]){
                int v = vec[0];
                int wt = vec[1];
                
                if(dist + wt < res[v]){
                    res[v] = dist + wt;
                    pq.push({res[v], v});
                }
            }
        }
        return res;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends