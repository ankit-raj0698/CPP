//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfsBipartite(vector<int>adj[], vector<int> &color, int u, int currColor){
        color[u] = currColor;
        for(int v: adj[u]){
            if(color[v] == -1){
                //currColor = 1 - currColor;
                if(dfsBipartite(adj, color, v,1 - currColor) == false)
                    return false;
            }
            else if(color[v] == currColor)
                return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            if(dfsBipartite(adj, color, i, 0) == false)
	                return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends