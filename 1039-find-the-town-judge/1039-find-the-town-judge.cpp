class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int> count(n+1,0);
        
        for(auto &vec: trust){
            int u = vec[0];
            int v = vec[1];
            
            // u can't be judge so decrement the count
            count[u]--;
            // v can be judge so increment the count
            count[v]++;
        }
        
        // everyone trusts judge so indegree of judge will be n-1
        // judge trusts no one so outdegree will be 0
        
        for(int i = 1; i <= n; i++){
            if(count[i] == n -1)
                return i;
        }
        
        return -1; 
    }
};