## Description

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
```

Return the following binary tree:

```
    3
   / \
  9  20
    /  \
   15   7
```

## Python3 recursive

First let's discuss the basics of an algorithm. We are given the preorder, and the inorder traversal, which are:

```
preorder:	root, left, right
inorder:	left, root, right
```

We will use the preorder traversal to determine the root, and leverage the inorder traversal for things like what is to the left or right. For instance, let's say this is our `preorder` and `inorder` traversals.

```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
```

If we construct the tree by the preorder order (`root` first, then `left`, and finally `right`), we can iterate through the `preorder` list to determine what our next root will be. Since the `inorder` traversal is `left`, then `root`, then `right`, we can split the inorder traversal by the root. The left side will be the left part of the tree, the right part will be the right part of the tree from the context of the current node. Then we can make the node, and set the left side to a recursive call fo the algorithm with the left part of the inorder traversal, and the right side equal to a recurisve call of the algorithm with the right part of the inorder traversal.

So my original algorithm to do this, wasn't that effecient. That was because it relied on the `index()` function, and list manipulation. A bettter way would be to just keep the indexes in a hash map, and just keep track of what indexes are for the current scope. Also the reason why we need `preorderIndex` to be a nonlocal, is because we won't be sure what the `preorderIndex` is for a recursive call, at the time we make it. This is due to the fact that when we make the recursive call, we aren't sure how many recursive calls will be made.

The runtime cost associated with this algorithm is `O(n)`, since we have to make a recursive call for each node. The memory cost is also `O(n)` since we have to enumerate a `TreeNode` for each input (`n` is the number of inputs).

So here is the algorithm:

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        # Check for an empty tree
        if (preorder == []) or (inorder == []):
            return None
        
        # Helper function for recursive calls
        def constructTree(leftIndex, maxIndex):

            # See if we exhausted this part of the tree
            if leftIndex == maxIndex:
                return None
            
            # We need the preorderIndex as a nonlocal    
            nonlocal preorderIndex
            
            # Construct the root node
            rootValue = preorder[preorderIndex]
            root = TreeNode(rootValue)
            
            # Increment the preorder index
            preorderIndex += 1

            # Grab the index of the current root value
            # From the inorder sequence 
            newIndex = hashMap[rootValue]
            
            # Recursively construct the children
            root.left   = constructTree(leftIndex, newIndex) 
            root.right  = constructTree(newIndex + 1, maxIndex)
            
            # Return the root
            return root
           
        # Construct the hash map
        hashMap = {}
        for i in range(0, len(inorder)):
            hashMap[inorder[i]] = i
        
        # Initialize the inorder index
        preorderIndex = 0

        # Construct the tree
        return constructTree(0, len(inorder))
```