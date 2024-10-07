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
    void inorder(TreeNode* root, int &mini, int &prev){
        if(!root)
            return;
        inorder(root->left, mini, prev);
        if(prev != -1)
            mini = min(mini, root->val - prev);
        prev = root->val;
        inorder(root->right, mini, prev);
    }
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        int prev = -1;
        inorder(root, mini, prev);

        return mini;
        
    }
};