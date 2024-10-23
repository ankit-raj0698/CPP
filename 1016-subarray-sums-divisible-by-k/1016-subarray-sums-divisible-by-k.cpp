// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int currNode, int currColor){
    color[currNode] = currColor;
    for(auto v: adj[currNode]){
        if(color[v] == -1){
            if(!dfs(adj, color, v, 1 - currColor))
                return false;
        }
        else if(color[v] == currColor)
            return false;
    }
    return true;
}

int main() {
   int n, m;
   cout << "enter n and m" << endl;
   cin >> n >> m;
   unordered_map<int, vector<int>> adj;
   int x, y;
   for(int i = 0; i < m; i++){
       cout << "enter x & y ";
       cin >> x >> y;
       adj[x].push_back(y);
       adj[y].push_back(x);
       cout << endl;
   }
   
   vector<int> color(n+1, -1);
   for(int i = 1; i <= n; i++){
       if(color[i] == -1){
           if(!dfs(adj, color, i, 0))
                cout << "No" << endl;
       }
   }
   
   cout << "Yes" << endl;
   
}