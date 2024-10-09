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
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        
        string rootVal = to_string(root->val);

        if(!root->left && !root->right)
            return  rootVal;

        string left = tree2str(root->left);
        string right = tree2str(root->right);

        if(root->left == NULL)
            return rootVal + "()" + "(" + right + ")";
        if(root->right == NULL)
            return rootVal + "(" + left + ")";
        
        return rootVal + "(" + left + ")" + "(" + right + ")";
        
    }
};