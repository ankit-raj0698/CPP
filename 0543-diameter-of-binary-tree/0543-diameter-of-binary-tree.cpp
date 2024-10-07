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

    // pair<int,int> ->> diameter, height
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0,0};
        
        pair<int, int> leftSubtree = solve(root->left);
        pair<int, int> rightSubtree = solve(root->right);

        int op1 = leftSubtree.first;
        int op2 = rightSubtree.first;
        int op3 = leftSubtree.second + rightSubtree.second;

        pair<int, int> ans;
        ans.first = max({op1, op2, op3});
        ans.second = 1 + max(leftSubtree.second, rightSubtree.second);

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int, int> ans = solve(root);
        return ans.first;
    }
};