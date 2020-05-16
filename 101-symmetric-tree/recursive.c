/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkNode(struct TreeNode * left, struct TreeNode * right)
{

	// Check if children of are null
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
    return checkNode(left->left, right->right) && checkNode(left->right, right->left);
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
        return checkNode(root->left, root->right);
    }
    
    // If the code hits here, it can't possibly be symmetric
    return false;
}

