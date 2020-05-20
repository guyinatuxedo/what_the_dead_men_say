## Description

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

```
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
```

Return the following binary tree:

```
    3
   / \
  9  20
    /  \
   15   7
```

## Python3 Recursive

The algorithm for this is pretty close to `105`. Instead of getting the `preorder` we get the `postorder`. This is similar, just shifted over by one (`left->right->root` instead of `root->left->right`). if we traverse the `postorder` backwards, we get a sequence that resembles the `preorder`, instead it goes right first then left. So if we just make this change to our algorithm to traverse the `postorder` backwards, while accounting for the change we end up with this algorithm.

The runtime cost associated with this algorithm is `O(n)`, since we have to make a recursive call for each node. The memory cost is also `O(n)` since we have to enumerate a `TreeNode` for each input (`n` is the number of inputs).

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
    	# Check for an empty tree
        if (postorder == []) or (inorder == []):
            return None
        
        # Helper function for recursive calls
        def constructTree(leftIndex, maxIndex):

            # See if we exhausted this part of the tree
            if leftIndex == maxIndex:
                return None
            
        	# We need the postorderIndex as a nonlocal    
            nonlocal postorderIndex
            
            # Construct the root node
            rootValue = postorder[postorderIndex]
            root = TreeNode(rootValue)
            
            # Increment the inorder index
            postorderIndex -= 1

            # Grab the index of the current root value
            # From the inorder sequence 
            newIndex = hashMap[rootValue]
            
            # Recursively construct the children
            root.right  = constructTree(newIndex + 1, maxIndex)
            root.left   = constructTree(leftIndex, newIndex) 

            
            # Return the root
            return root
           
        # Construct the hash map
        hashMap = {}
        for i in range(0, len(inorder)):
            hashMap[inorder[i]] = i
        
        # Initialize the inorder index
        postorderIndex = len(postorder) - 1

        # Construct the tree
        return constructTree(0, len(inorder))
```