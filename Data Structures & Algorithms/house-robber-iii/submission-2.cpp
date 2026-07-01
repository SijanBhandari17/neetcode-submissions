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

pair<int, int> recurse(TreeNode* root) {
    if (!root) return {0, 0}; 

    pair<int, int> leftChoices = recurse(root->left);
    pair<int, int> rightChoices = recurse(root->right);

    int robThis = root->val + leftChoices.second + rightChoices.second; 
    int skipThis = max(leftChoices.first, leftChoices.second) + 
                   max(rightChoices.first, rightChoices.second);

    return {robThis, skipThis};
}

int rob(TreeNode* root) {
    pair<int, int> result = recurse(root);
    return max(result.first, result.second);
}

};