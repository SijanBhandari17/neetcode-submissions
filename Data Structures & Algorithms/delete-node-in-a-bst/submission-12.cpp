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

    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while (curr && curr->val != key) {
            prev = curr;
            if (curr->val > key) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (!curr) return root;


        if(curr->right && curr->left){
            TreeNode *succPar = curr;
            TreeNode *succ = curr->right;

            while(succ->left){
                succPar = succ;
                succ = succ->left;
            }  
            curr->val = succ->val;
            prev = succPar;
            curr = succ;       
        }

        TreeNode *child = (curr->left) ? curr->left : curr->right;

        if (!prev) {
            delete curr;
            return child;
        }

        if (prev->left == curr) prev->left = child;
        else prev->right = child;

        delete curr;
        return root;

    }
};