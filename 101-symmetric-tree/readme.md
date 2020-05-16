## Description:

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
 

But the following [1,2,2,null,3,null,3] is not:

```
    1
   / \
  2   2
   \   \
   3    3
```

## Solution - Recursively C

Below is the source code for this solution. We start off by running a series of checks on the root node, to ensure that it's worth starting to recursively make calls down the rest of the tree. The process of veryfing nodes is simple. First off we check for nulls. If the nulls are not symmetrical, then there is no way the tree can be symmetrical. If the nulls are symmetrical, we know that piece of the tree is symmetrical. Proceeding that, we check if the values of the nodes are equal. If so, we continue checking for a symmetrical tree. When we check a subsequent layer of the tree, we check the opposite ends of each side, since they are the ones that need to be equal in order for the tree to be symmetrical.

This algorithm has an O(n) time and space complexity. The time complexity comes that in order for this algorithm to verify that a tree is symmetrical, it needs to look at each node once. The space complexity comes from the fact that the number of function calls made directly scales with the number of nodes in the tree. The more nodes in the tree, the more function calls are made, which results in more memory used (assuming that the algorthim doesn't exit out before hand due to an unsymmetrical tree).

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkNodes(struct TreeNode * left, struct TreeNode * right)
{

	// Check if children are null
    if ((left == NULL) && (right == NULL))
    {
        return true;
    }
    
    // Check if the node is missing one child
    if ((left == NULL) || (right == NULL))
    {
        return false;
    }    
    
    // Check if the node's children are equal
    if ((left->val != right->val))
    {
        return false;
    }
    
    // Run the algorithm recursively across the rest
    return checkNodes(left->left, right->right) && checkNodes(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
	// Check if root is null
    if (root == NULL)
    {
        return true;
    }
    
    // Check if the children of root is null
    if ((root->left == NULL) && (root->right == NULL))
    {
        return true;
    }
    
    // Check if a single child of root is null
    if ((root->left == NULL) || (root->right == NULL))
    {
        return false;
    }
    
    // Check if the children of root are equal
    if ((root->left->val == root->right->val))
    {
    	// Recursively Check the rest of the nodes in the tree
        return checkNodes(root->left, root->right);
    }
    
    // If the code hits here, it can't possibly be symmetric
    return false;
}
```