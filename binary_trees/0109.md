## Description

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

```
Given the sorted linked list: [-10,-3,0,5,9],
```

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

```
      0
     / \
   -3   9
   /   /
 -10  5
```


## Recursive Python3

Starting off, my original algorithm I made for this wasn't the best. It involved populating the tree from the leftmost bottom node, to the root, the rightmost bottom node. I also kept track of several nodes, and handled rotations myself. 

The algorithm I documented here was from leetcode, and a lot simpler. Essentially the algorithm incorporates two parts. The first part is to convert the linked list to an array, and get the length of that array. The reason for this is so accessing a value at an index in the array becomes an `O(1)` operation. 

Proceeding that, we start making the recursive calls to populate the tree. For each call to the algorithm, the parameters are two indexes which represent the begining and end index which is the range for that recursive call. The node generated will be the node in the middle of those two indexes, which will serve as a root. Due to the principles of a bst, this node should always be the root. Proceeding that we generate the children for the root via recursive calls. The indexes for the left, has the same starting index but the end index is the index immediately before the root index. The right recursive call has the same ending index, and the begining index is the index immediately after the middle.

In addition to that, there are several checks. The first check is if the beginning index is greater than the end index which happens when we have reached an ara of the array that there isn't a node. The second check is when the begining index is equal to the ending index, which signifies that there are no children for that root. 

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    # Helper function to convert linked list to array
    def convertListToArray(self, head: ListNode):
        array = []
        count = 0
        
        # Populate array / count
        while head:
            array.append(head.val)
            count += 1
            head = head.next        
        return array, count
    
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        # Check for null input tree
        if head == None:
            return None
        
        # Convert the linked list to an array
        array, count = self.convertListToArray(head)
        
        # Recursive function to convert array to bst
        def convertArrayToBST(startIndex, endIndex):
            # case where there are no more nodes down this path
            if (startIndex > endIndex):
                return None
            
            # grab the index for this node, and make it
            middleIndex = (startIndex + endIndex) // 2
            value = array[middleIndex]
            node = TreeNode(value)
            
            # If there are children, for this node, populate it
            if (startIndex != endIndex):
                node.left = convertArrayToBST(startIndex, middleIndex - 1)
                node.right = convertArrayToBST(middleIndex + 1, endIndex)           
                
            return node
        
        # Convert the array to a bst
        return convertArrayToBST(0, count - 1)
```