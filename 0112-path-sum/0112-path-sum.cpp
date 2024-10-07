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

    bool solve(TreeNode* root, int targetSum){
        if(!root)
            return false;
        if(!root->left && !root->right && root->val == targetSum)
            return true;
        
        bool left = solve(root->left, targetSum - root->val);
        if(left)
            return left;
        bool right = solve(root->right, targetSum - root->val);

        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        return solve(root, targetSum);
    }
};