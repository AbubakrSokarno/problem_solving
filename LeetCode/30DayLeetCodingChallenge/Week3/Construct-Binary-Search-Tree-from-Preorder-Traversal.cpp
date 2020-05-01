// Problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return NULL ;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int x = 1 ; x < preorder.size() ; x++) {
            int i = preorder[x] ;
            TreeNode* last ;
            TreeNode* traversal ;
            traversal = root  ;
            while (traversal != NULL) {
                last = traversal ;
                if (i > traversal->val) {
                    traversal = traversal->right ;
                } else {
                    traversal = traversal->left  ;
                }
            }
            TreeNode* item = new TreeNode(i);
            if (i > last->val)
                last->right = item ;
            else
                last->left = item ;
        }
        return root ;
    }
};
