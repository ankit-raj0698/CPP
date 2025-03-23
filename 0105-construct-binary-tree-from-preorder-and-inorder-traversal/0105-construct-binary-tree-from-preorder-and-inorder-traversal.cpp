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
    int n;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &findPos, int &ind, int start, int end){

        if(ind >= n || start > end)
            return NULL;

        int ele = preorder[ind++];
        TreeNode* root = new TreeNode(ele);
        int pos = findPos[ele];

        root->left = solve(preorder, inorder, findPos, ind, start, pos-1);
        root->right = solve(preorder, inorder, findPos, ind, pos + 1, end);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        unordered_map<int,int> findPos;
        for(int i = 0; i < n; i++)
            findPos[inorder[i]] = i;
        int ind = 0;
        int start = 0;
        int end = n-1;
        return solve(preorder, inorder, findPos, ind, start, end);
    }
};