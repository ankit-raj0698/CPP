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
    void inorder(TreeNode* root, vector<int> &ans){
        if(!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);       
    }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        //inorder(root, ans);

        TreeNode* curr = root;
        while(curr){
            // L N R
            if(curr->left == NULL){
                // left is null so now print and move right
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // find the rightmost node of left subtree
                TreeNode* leftchild = curr->left;
                while(leftchild->right != NULL)
                    leftchild = leftchild->right;
                
                // now join the rightmost child with curr node
                leftchild->right = curr;

                // do curr->left = null but also move the curr pointer to left
                TreeNode* temp = curr->left;
                curr->left =  NULL;
                curr = temp;
            }
        }

        return ans;
        
    }
};