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

    // pair<bool,int> ->> isBalanced, height
    pair<bool, int> solve(TreeNode* root){
        if(!root)
            return {true,0};
        
        pair<bool, int> leftSubtree = solve(root->left);
        pair<bool, int> rightSubtree = solve(root->right);

        bool isLeftBalanced = leftSubtree.first;
        bool isrightBalanced = rightSubtree.first;
        bool heightDiff = abs(leftSubtree.second - rightSubtree.second) <= 1;

        pair<bool, int> ans;
        ans.first = isLeftBalanced && isrightBalanced && heightDiff;
        ans.second = 1 + max(leftSubtree.second, rightSubtree.second);

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = solve(root);
        return ans.first;
    }
};