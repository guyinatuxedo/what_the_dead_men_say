## Description:

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

```
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
```
 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

```
    3
   / \
  9  20
    /  \
   15   7
```

Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

```
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
```

Return false.


## C Recursive

So this algorithm checks for a balanced tree. It does this by looking at each node, and seeing if the maximum depth of the left branch is balanced with maximum depth of the right branch (if there is a less than 2 difference between depths, means it's balanced). If it is a balanced tree, then from the perspective of each node, the maximum depth of the left and right branches will be balanced. If it isn't a balanced tree, then at least one node will not have a balanced left and right side.

The cost of running this algorithm is `o(n * log(n))`. The reason for this, is in order for the algorithm to return true, it has to verify that the child branches of each node are balanced. For each verification, we need to grab the maximum depth of left and right sides, which adds it's own work that scales directly with the number of nodes (however each time we go to a child, the number of nodes decreases). 

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Get the max depth of a branch
int getMaxDepth(struct TreeNode* node, int depth)
{
    int leftDepth, rightDepth;

    rightDepth = leftDepth = depth + 1;

    // If node is null, depth is the given depth
    if (node == NULL)
    {
        return depth;
    }
    
    // Get the depths of the left, and right branches
    if (node->right != NULL)
    {
        rightDepth = getMaxDepth(node->right, depth + 1);        
    }
    
    if (node->left != NULL)
    {
        leftDepth = getMaxDepth(node->left, depth + 1);
    }
    
    // Return the greater depth
    if (leftDepth >= rightDepth)
    {
        return leftDepth;
    }
    
    return rightDepth;
}


bool isBalanced(struct TreeNode* root){
    int leftDepth, rightDepth, diff;

    // If root is null, the tree is balanced
    if (root == NULL)
    {
        return true;
    }
    
    // Get the depths of the list and right brancheds
    leftDepth = getMaxDepth(root->left, 1);
    rightDepth = getMaxDepth(root->right, 1);
    
    // Get the difference
    diff = abs(leftDepth - rightDepth);
    
    // Recursively check the rest of the forks
    if (diff < 2)
    {
        return isBalanced(root->left) & isBalanced(root->right);
    }
    
    return false;
}
```