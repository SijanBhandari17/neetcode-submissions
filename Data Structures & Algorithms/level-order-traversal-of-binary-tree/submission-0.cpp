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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        int numChild = 0;
        int toRunFor = 1;
        while (q.size() != 0) {
            vector<int> out;
            while (toRunFor != 0) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                    numChild++;
                }
                if (curr->right) {
                    q.push(curr->right);
                    numChild++;
                }
                out.push_back(curr->val);
                toRunFor--;
            }
            res.push_back(out);
            toRunFor = numChild;
            numChild = 0;
        }
        return res;
    }
};
