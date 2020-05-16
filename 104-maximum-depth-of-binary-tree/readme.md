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