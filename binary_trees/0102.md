## Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

```
    3
   / \
  9  20
    /  \
   15   7
```

return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```

## Python3 iterative

This solution essentially just iterates through each level of the tree. It models each level as a list, where the first item is the leftmost node, and thelast item in is the rightmost node. 

When I iterate through a level, I add the values to one list. This is because the return value is a list of lists. While I am adding the values to one list, I will append the children to another list, which we will iterate through in the next for loop.

The runtime cost for this algorithm is an `O(n)`, since it has to analyze every node, and the work lineraly scales with the number of nodes. The space requirement is `O(n)`, because the size of the returned data structure depends directly on the input, so the more input nodes you have, you will have a direct linear increase in the size of the output.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        # Check for a root equal to none
        if root is None:
            return []
        
        # Initiate the lists
        returnList = []
        vals = []
        currentList = [root]
        
        while currentList != []:
            # Clear out some of the lists
            vals = []
            newList = []
            
            # Iterate through all the nodes for this depth
            for node in currentList:
                
                # If node is null, continue
                if node is None:
                    continue

                # Add the value, and the children
                vals.append(node.val)
                newList.append(node.left)
                newList.append(node.right)
                
            # Set the current list to the next level, 
            currentList = newList

            # Check if we need to append this vals list
            if vals != []:
                returnList.append(vals)
                
        return returnList
```