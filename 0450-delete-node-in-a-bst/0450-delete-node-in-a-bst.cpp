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
    int findMax(TreeNode* root){
        TreeNode* curr = root;
        while(curr->right)
            curr = curr->right;
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(key == root->val){
            // 0 child
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            // 1 child
            else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 2 child
            else if(root->left && root->right){
                // find max in left subtree
                int maxInLeftSubtree = findMax(root->left);
                // swap root value with maxInLeftSubtree
                root->val = maxInLeftSubtree;
                // now delete the maxInLeftSubtree from left subtree
                root->left = deleteNode(root->left, maxInLeftSubtree);
            }

        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else
            root->right = deleteNode(root->right, key);
        
        return root;
        
    }
};