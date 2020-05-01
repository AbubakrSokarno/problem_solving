// Problem Link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3314/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mx = INT_MIN ;
public:
    int dfs (TreeNode* root) {
        if (root == NULL) {
            return 0 ;
        }
        int left_mx = max(0,dfs(root->left));
        int right_mx = max(0,dfs(root->right));

        mx = max(mx , left_mx + right_mx  + root->val ) ;

        return max(left_mx,right_mx) + root->val ;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root) ;
        return mx ;
    }
};
