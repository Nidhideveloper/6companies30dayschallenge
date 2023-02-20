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
public:
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left = solve(root->left);
        int ls = left.first; 
        int lc = left.second; 
        
        auto right = solve(root->right);
        int rs = right.first; 
        int rc = right.second; 
        
        int s = root->val + ls + rs;
        int c = lc + rc + 1;
        
        if(root->val == s/c) ans++;
        return {s,c};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};