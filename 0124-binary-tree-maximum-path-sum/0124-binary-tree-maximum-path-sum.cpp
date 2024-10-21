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
    int maxSum;
    
    int solve(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        // we have now 3 options
        // left ya right me se jo bhi max hai usme root add kr do
        // both left and right is giving -ve result so only root is good
        // left,right,root combines to give max
        
        int op1 = max(left,right) + root->val;
        int op2 = root->val;
        int op3 = left + right +  root->val;
        
        
        maxSum = max({maxSum, op1, op2, op3});
        
        // op3 return nhi kr skte kyo ki agar valid path banana hai to ya to root return
        // hoga ya phir root + left ya right child me se koi ek
        return max(root->val , root->val + max(left, right));
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
        
    }
};