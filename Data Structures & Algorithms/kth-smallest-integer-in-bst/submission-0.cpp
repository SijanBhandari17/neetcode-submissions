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
    int kth = 0;
    int cnt = 0;

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 1;

        cnt += kthSmallest(root->left,k);
        if(cnt == k){
            kth = root->val;
        }
        cnt += kthSmallest(root->right,k);
        return kth;
    }
};
