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
    int isGreater(TreeNode *root, int maxInPath){
        if(!root) return 0;
        int returnVal = 0;

        if(root->val >= maxInPath) {
            maxInPath = root->val;
            returnVal = 1;
        }
        return returnVal + isGreater(root->left,maxInPath) + isGreater(root->right,maxInPath); 
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return isGreater(root->left,root->val) + isGreater(root->right,root->val)  + 1 ;
    }
};
