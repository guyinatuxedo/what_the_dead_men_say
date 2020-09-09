## Description

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

return its zigzag level order traversal as:

```
[
  [3],
  [20,9],
  [15,7]
]
```

## Python3 Iterative Breadth-First Search

This algorithm is pretty close to the one in `102` (the Python3 Iterative one). The main difference is that every other level, we have to swap the order from left to right to right to left, and back. I do this by keeping a value called `forward` which is responsible for specyfing which way the ordering of a level goes. When inserting nodes, I prepend them to the start of the list. The only difference between ordering the nodes one way or another, is if I add the left or right node first.

In addition to that, I use a deque instead of a list as the data structure for storing the nodes for each level. The reason for this is because my algorithm requires insertion at the beginning of a list, which deques will give us a better runtime than `insert()` with lists.

The runtime and memory costs are still `O(n)`, just like with `102` for the same reasons.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Import collections to get deques
import collections

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        
        # Check for a root equal to none
        if root is None:
            return []
        
        # Initiate the lists
        returnList = []
        vals = []

        # Use a deque for runtime purpose
        currentDeque = collections.deque([root])
        
        # Our value for knowing what order to add nodes
        forward = False
        
        while currentDeque:
            # Clear out some of the lists/deque
            vals = []
            newDeque = collections.deque()
            
            # Iterate through all the nodes for this depth
            for node in currentDeque:

                # If node is null, continue
                if node is None:
                    continue
                              
                # Add the value, and the children
                vals.append(node.val)
                if forward == False:
                    newDeque.appendleft(node.left)   
                    newDeque.appendleft(node.right)

                else:
                    newDeque.appendleft(node.right)   
                    newDeque.appendleft(node.left)
           
            # Set the current deque to the next level, 
            currentDeque = newDeque
            
            # Swap the forward value
            forward = ~(forward)

            # Check if we need to append this vals list
            if vals != []:
                returnList.append(vals)
                
        return returnList        
```