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
    bool solve(TreeNode* root, TreeNode* mini, TreeNode* maxi){
        if(!root)
            return true;
        
        if(mini && root->val <= mini->val)
            return false;
        
        if(maxi && root->val >= maxi->val)
            return false;
        
        bool left = solve(root->left, mini, root);
        bool right = solve(root->right,  root, maxi);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {

        if(!root)
            return true;

        return solve(root, NULL, NULL);
        
    }
};