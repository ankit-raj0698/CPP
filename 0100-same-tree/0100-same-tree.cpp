/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool solve(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr && q)
            return false;
        if(p && q == nullptr)
            return false;
        
        bool left = solve(p->left,q->left);
        bool right = solve(p->right, q->right);
        bool data = p->val == q->val;
        
        return left && right && data;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};