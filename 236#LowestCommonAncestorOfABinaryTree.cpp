/*
	problem:	Lowest Common Ancestor of a Binary Tree
	difficulty:	medium
	description:	Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
			According to the definition of LCA on Wikipedia: 
			“The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants 
				(where we allow a node to be a descendant of itself).”
  	tags:		Tree
	
	solution:	if root == NULL, then we can return NULL means there is no such node;
			if root is one of the two nodes, return root cause "we allow a node to be a descendant of itself";
			at this point we can ensure the two nodes are in the subtree of root, so 
				recursively call this function to calculate left and right child of root.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)    return NULL;
        if(p == root || q == root)  return root;
        TreeNode *leftAnc = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAnc = lowestCommonAncestor(root->right, p, q);
        if(leftAnc != NULL && rightAnc != NULL)
            return root;
        else if(leftAnc != NULL)
            return leftAnc;
        else
            return rightAnc;
    }
};
