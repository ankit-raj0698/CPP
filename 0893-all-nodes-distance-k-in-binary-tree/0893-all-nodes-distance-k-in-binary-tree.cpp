/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void treeToGraph(TreeNode* root, unordered_map<int, vector<int>> &adj){
        if(!root)
            return;
        
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            treeToGraph(root->left, adj);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            treeToGraph(root->right, adj);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        
        
        treeToGraph(root, adj);
        
        int n = adj.size();
        vector<int> visited(n,0);
        
        if(k > n)
            return ans;
               
        q.push(target->val);
        visited[target->val] = 1;

        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size-- && level <= k){
                int u = q.front();
                q.pop();

                if(level == k){
                    ans.push_back(u);
                }

                for(auto v: adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }

            level++;
            if(level > k)
                break;
        }

        return ans;

    }
};