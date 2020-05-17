## Recursive C

So for this algorithm, we have to find the minimum depth, which is the minimum distance between the root and a leaf node. For my algorithm, we first check if the root is null (since if it is, it can already have one depth). Then we begin the recursive calls. For the recursive calls, there are realistically three cases. One of which is both children are null, in which have reached a leaf node and report it's depth. The next case is where we have one null child, and one non null child, in which case we just continue searching for the depth down the non-null path and return it. The final case is where we have two non null children, in which for that case we grab the minimum depth of both the branches, and return the lesser of the two.

The runtime cost of this algorithm is `O(n)`, since this algorithm will have to look at every node once (`n` is number of nodes in the tree). The worst possible memory cost is also `O(n)` since the memory allocation primarily comes from the stack variables of each recursive funciton call, which happens for each node that isn't the root. However if the tree is balanced, a memory cost of `O(log(n))` can be reached if the tree is balanced. This is due to the fact that our algorithm is a depth first search, so if the tree is balanced that means that there is less memory needed at one particular time (the reason for the `log(n)` as the reduced size comes from the characteristics of a balanced bst).

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int getMinDepthRecursive(struct TreeNode* node, int depth)
{
    int leftDepth, rightDepth;
    
    // If both children are null, we have reached a leaf node
    if ((node->right == NULL) && (node->left == NULL))
    {
        return depth;    
    }
    
    // If either of these checks are true, one child is null and the other isn't
    // So we only need to check one branch

    if ((node->right == NULL))
    {
        
        leftDepth = getMinDepthRecursive(node->left, depth + 1);
        return leftDepth;
    }
   
    if ((node->left == NULL))
    {
        rightDepth = getMinDepthRecursive(node->right, depth + 1);
        return rightDepth;
    }

    // This is for when both children are not null
    // Check the length of both child branches, return the lesser

    leftDepth = getMinDepthRecursive(node->left, depth + 1);
    rightDepth = getMinDepthRecursive(node->right, depth + 1);
    
    if (leftDepth < rightDepth)
    {
        return leftDepth;
    }
    
    return rightDepth;
}

int minDepth(struct TreeNode* root){
    
    int leftDepth, rightDepth;
    
    // If the root is null, the only depth is 0
    if (root == NULL)
    {
        return 0;
    }
    
    // Recurively grab the minimum length
    return getMinDepthRecursive(root, 1);
}
```