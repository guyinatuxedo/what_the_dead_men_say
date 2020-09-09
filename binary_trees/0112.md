## C Recursive Backtracking

So for this problem, we have to see if there exists a path (a string of nodes from the root node to a leaf node) that the sum of all of the nodes is equal to a value. First off I check if the root is null, since if it's null there are no paths, so we know it's false. After that, we start making recursive calls of `getPathSum()`. This will traverse the tree starting with the left-most nodes, adding the values together as we go along. Once we reach a leaf node, we see if the sumnation is equal to three (and if so, we return true). If not we backtrack to the previous node, and try traversing down the right path. 

The runtime cost of this algorithm is `O(n)` in the worst case, since this algorithm will have to look at every node (one recursive call per node). The memory cost can range from `O(n)` to `O(log(n))`. Since the memory cost is mainly associated with the memory of the recursive calls, the memory cost directly scales with the number of the size of the call stack. In the best case the bst is balanced, since that will end up with the shortest call stack (`O(log(n))`). The worst case is when the tree is not balanced at all, which will lead to the largest call stack.

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool getPathSum(struct TreeNode* node, int sumnation, int key)
{
    
    // Check the left side first
    if (node->left != NULL)
    {
        if (getPathSum(node->left, sumnation + node->val, key) == true)
        {
            return true;
        }
    }
    
    // Backtrack to the right side
    if (node->right != NULL)
    {
        if (getPathSum(node->right, sumnation + node->val, key) == true)
        {
            return true;
        }
    }
    
    // Check if we reached a leaf node
    if (((node->right == node->left ) && (node->right == NULL) )
    {
        // Check if the path sum is equal to the desired value
        if (sumnation + node->val) == key)
        {
            // We found the path
            return true;
        }
    }
    
    // Not this path
    return false;
    
}

bool hasPathSum(struct TreeNode* root, int sum){
    // If the root node is null, there's no 
    // possible path to reach a constant
    if (root == NULL)
    {
        return false;
    }
    
    // Recursively find the path
    return canFind = getPathSum(root, 0, sum);
}
```