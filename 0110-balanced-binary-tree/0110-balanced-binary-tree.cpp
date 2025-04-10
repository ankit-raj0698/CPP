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
    typedef pair<bool,int> p;
    p solve(TreeNode* root){
        if(!root)
            return {true,0};
        
        p left = solve(root->left);
        p right = solve(root->right);

        p ans;
        ans.first = left.first && right.first &&
                     abs(left.second - right.second) <= 1;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        
        p ans = solve(root);
        return ans.first;
        
    }
};