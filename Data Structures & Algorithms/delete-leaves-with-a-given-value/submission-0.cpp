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

    bool recurse(TreeNode *root,int target){
        if(!root) return false;
        bool isLeftDeleted = recurse(root->left,target);
        bool isRightDeleted = recurse(root->right,target);
        
        if(isLeftDeleted) {
            TreeNode *temp = root->left;
            root->left = nullptr;
            delete temp;
        }
        if(isRightDeleted){
            TreeNode *temp = root->right;
            root->right = nullptr;
            delete temp;
        }

        if(root->val == target  && !root->left && !root->right){
            return true;
        }

        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool result = recurse(root,target);
        if(result){
            delete root;
            return nullptr;
        } 
        return root;
    }
};