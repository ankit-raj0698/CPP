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

    bool solve(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2)
            return true;
        if(!node1 || !node2)
            return false;
        
        // if(node1->val != node2->val)
        //     return false;

        bool left = solve(node1->left, node2->right);
        bool right = solve(node1->right, node2->left);
        bool checkVal = node1->val == node2->val;

        return left && right && checkVal;

    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return solve(root->left, root->right);
        
    }
};