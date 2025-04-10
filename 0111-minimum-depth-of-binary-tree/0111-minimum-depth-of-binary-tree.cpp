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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        // when we are returning min(left,right) + 1, it might happen that
        // left or right is returning 0, so min will be 0 from that side
        // and hence give wrong answer
        if(left == 0)
            return right + 1;
        else if(right == 0)
            return left + 1;

        return min(left,right) + 1;
    }
};