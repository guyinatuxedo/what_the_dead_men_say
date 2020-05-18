## Description:

## C DFS Recursive Solution


So this algorithm is repsonsible for finding the maximum depth of a binary tree (depth being the distance from the root to a leaf node, which is a node with no children). I use a Depth First Search algorithm for this. I do this by recursively going through all of the nodes, and having one function call for the helper function `checkDepth` make another recursive call for each non-null child it has. Each time another recursive call is made, the depth is incremented by `1` to reflect the deeper layer. 

With the helper function `checkDepth`, there are really 3 cases we have to consider. The first is that both children are null, in which case we have reached a leaf node and can just return the depth. The second is when one child is null, and one is not. Due to the nature of how Binary Trees work, the non-null branch will have a greater depth so we just return the depth of that branch. This check happens after the one for the leaf node, since that way we only have to check if the opposing child is null (because of the previous check we know they are both not null). This saves us a few instructions. The last case is where both children are not null. In which case we just grab the depth of both branches, and return whichever one is greater. 


In terms of runtime, this is an `O(n)` algorithm, where `n` is the number of nodes. That is because in order for this algorithm to run completely, it needs to look at each node. The memory cost associated with this algorithm manly comes from the local stack variables associated with each function call. As a result the memory cost is `o(n)`

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkDepth(struct TreeNode *node, int depth)
{
    int depth0, depth1;

	// Check if children are both null, which means we have a leaf node    
    if (((node->right) == (node->left)) && ((node->right) == (NULL)))
    {
        return depth + 1;
    }
    
    // These next two conditionals are for when
    // you have one child null, and one not null
    // the not null child branch will have the greater depth

    // If right child is not null, and left child is
    // Return depth of left child
    if ((node->left) == NULL)
    {
        return checkDepth(node->right, depth + 1);
    }

    // Same for last check, but flipped direction
    if (node->right == NULL)
    {
        return checkDepth(node->left, depth + 1);
    }
    
    // This code path is for when both children are not null
    // Grab the depth of both branches, return the larger one

    depth0 = checkDepth(node->left, depth + 1);
    depth1 = checkDepth(node->right, depth + 1);
    
    if (depth0 > depth1)
    {
        return depth0;
    }
    
    return depth1;
}


int maxDepth(struct TreeNode* root)
{
    int depth0, depth1;
    depth0 = depth1 = 1;
    
    // If root is null, we know the length
    if (root == NULL)
    {
        return 0;
    }
    
    // Recursively grab the max depth 
	return checkDepth(root, 0);
}
```

## Python3 Iterative

So this solution utilizes a queue to iterate through a tree. We start off by checking if the root is None, and if so it's balanced. Then we initialize the queue, and append the children of the root to the queue, and begin iterating through the tree. 

The queue contains all of the nodes that need to be analyzes, so when the queue is empty we have analyzed the entire tree. Each iteration of the loop will look at two nodes, which are opposite each other (since in order for the tree to be balanced, these two nodes will have the same value). The first check is if they are both None, since if they are this part of the tree is balanced. Then after that we check if either node is None, since if one is None and one isn't, then it isn't balanced. Then we check if the values are equal, and if they are this part of the tree is balanced. Proceeding that we append the children of those two nodes to the queue. We append the opposite children, that way the queue is structured in a way where the two nodes that must be equal in order for the tree to be symmetrical are right next to each other in the queue. This alogorithm will iterate through all of the nodes of one level, before proceeding to the next level.

The runtime requirement is `O(n)`, since the number of loop iterations directly scales with the number of nodes in a linear fashion. The major space requirment comes from the queue, which the space that takes up also directly scales with the number of nodes. As such the space complexity is `O(n)`

```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        
        queue = []
        
        queue.append(root.left)
        queue.append(root.right)
        
        while queue != []:
            # Pop off the first two elements
            left = queue.pop()
            right = queue.pop()
            
            # If both are none, this part is balanced
            if (left == right == None):
                continue
            
            # If only one node is none, tree is not balanced
            if (left == None) or (right == None):
                return False
            
            # If the node values are not equal, not balanced
            if (left.val != right.val):
                return False
            
            # Add the children to the queue
            queue.append(left.left)
            queue.append(right.right)
            
            queue.append(left.right)
            queue.append(right.left)
        
        # Iterated through entire tree, so it's balanced
        return True
```