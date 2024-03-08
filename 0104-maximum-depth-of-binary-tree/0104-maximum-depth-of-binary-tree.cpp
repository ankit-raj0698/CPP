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
    int maxDepth(TreeNode* root) {
        
        //Base case : smallest valid/invalid input
        //For tree smallest valid input would be null
        if(root==nullptr)
            return 0;
        
        //Hypothesis : find ht of root->left and root->right
        // for func(n) find func(n-1)      
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        //Induction : Extra work to be done
        //To calculate ht of tree find max ht of left,right subtree and add 1 for root node
        return 1 + max(left,right);    
        
    }
};