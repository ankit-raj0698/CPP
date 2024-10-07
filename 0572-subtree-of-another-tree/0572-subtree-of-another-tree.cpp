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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p && q)
            return false;
        if(p && !q)
            return false;
        
        bool leftSubtree = isSameTree(p->left, q->left);
        bool rightSubtree = isSameTree(p->right, q->right);
        bool checkVal = p->val == q->val;

        return leftSubtree && rightSubtree && checkVal;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // if both root and subroot is null return true
        if(!root && !subRoot)
            return true;
        
        // if subroot is null , return true
        if(!subRoot)
            return true;
        
        // root is null but subroot is not  null, so return false
        if(!root && subRoot)
            return false;
              
        // check if root and subroot are same
        if(isSameTree(root, subRoot))
            return true;
        
        // if root and subroot are not same then
        // check left and right subtree of root with subroot
        bool leftSubtree =  isSubtree(root->left, subRoot);
        bool rightSubtree =  isSubtree(root->right, subRoot);

        return leftSubtree || rightSubtree;
        
    }
};