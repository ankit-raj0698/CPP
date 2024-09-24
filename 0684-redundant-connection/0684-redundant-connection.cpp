class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void dsu(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent != y_parent){
            if(rank[x_parent] < rank[y_parent])
                parent[x_parent] = y_parent;
            else if(rank[x_parent] > rank[y_parent])
                parent[y_parent] = x_parent;
            else{
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,0);

        vector<int> ans;

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            if(find(u) == find(v)){
                ans.push_back(u);
                ans.push_back(v);
            }
            else
                dsu(u,v);
        }
        return ans;
    }
};