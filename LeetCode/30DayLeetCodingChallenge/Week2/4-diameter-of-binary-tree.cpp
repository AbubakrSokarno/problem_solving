/**
 * Problem Link :-
 * - https://leetcode.com/problems/diameter-of-binary-tree/
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int res = 0 ; 
public:
    int maxDepth(TreeNode* node)  
    {  
        if (node == NULL)  
            return 0;  
        else
        {  
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->left);  
            int rDepth = maxDepth(node->right);  

            /* use the larger one */
            if (lDepth > rDepth)  
                return(lDepth + 1);  
            else return(rDepth + 1);  
        }  
    }  
    
    int solve(TreeNode* root) {
        if (root == NULL) 
            return 0 ; 
        int leftSolve = solve(root->left) ;
        int rightSolve = solve(root->right) ;
        
        res = max(res,leftSolve+rightSolve) ; 
        
        return max(leftSolve,rightSolve) + 1 ;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        /*if (root == NULL) {
            return 0 ; 
        }
        
        int lheight = maxDepth(root->left) ; 
        int rheight = maxDepth(root->right);
        
        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);
        
        return max(lheight + rheight , max(ldiameter,rdiameter));*/
        
        solve(root) ;
        return res; 
    }
};
