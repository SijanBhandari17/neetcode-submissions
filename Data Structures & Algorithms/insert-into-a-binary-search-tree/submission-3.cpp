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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode *curr = root;
        TreeNode *prev = new TreeNode();
        while(curr){
            if(curr->val > val){
                prev = curr;
                curr = curr->left;
            }
            else{
                prev = curr;
                curr =  curr->right;
            }
        }
        if(prev->val > val) {
            prev->left = new TreeNode(val);
        }
        else{
            prev->right = new TreeNode(val);
        }
        return root;
        
    }
};