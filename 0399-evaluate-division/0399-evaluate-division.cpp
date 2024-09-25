class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited, string src, string dest, double product, double &ans){
        
        // when the node is already visited , return
        if(visited.find(src) != visited.end())
            return;
        
        // mark the current node as visited
        visited.insert(src);

        // when we reached dest, store the answer and return
        if(src == dest){
            ans = product;
            return;
        }

        // traverse the adjacent nodes
        for(auto p: adj[src]){
            string v = p.first;
            double val = p.second;
            // as you are traversing the adjacent node, update the product
            dfs(adj, visited, v, dest, product * val, ans);
        } 

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();

        // create an adj list storing edge wt in forward and backward direction
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u, 1.0/val});
        }

        vector<double> res;

        // find answer for query
        for(auto query: queries){
            string src = query[0];
            string dest = query[1];

            double ans = -1.0;

            //when src or dest is not in adj return -1.0 
            if(adj.find(src) == adj.end() || adj.find(dest) == adj.end())
                res.push_back(ans);
            else{
                // otherwise find the answer to queries
                double product = 1.0;
                // for each query create a visited set so that it is not affected by 
                // previous query
                unordered_set<string> visited;
                dfs(adj, visited, src, dest, product, ans);
                res.push_back(ans);
            }

        }

        return res;
        
    }
};