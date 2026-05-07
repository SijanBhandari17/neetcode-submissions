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

   private:
    int max_depth;
    int depth;

   public:
    Solution() : max_depth(0), depth(0) {}

    void sol(TreeNode *root){
        if (!root) return;
        depth++;
        if (max_depth <= depth) max_depth = depth;
        maxDepth(root->left);
        maxDepth(root->right);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        sol(root);
        return max_depth;
    }
};
