# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        idx_map = {val: i for i,val in enumerate(inorder)}
        self.pre_idx = 0;

        def helper(left,right):
            if left > right:
                return None
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1

            mid = idx_map[root_val]
            node = TreeNode(root_val)
            node.left = helper(left,mid - 1)
            node.right = helper(mid+1,right)
            return node
        return helper(0,len(preorder) - 1)