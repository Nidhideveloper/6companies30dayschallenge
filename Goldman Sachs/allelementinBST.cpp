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
    void dfs(TreeNode* root, vector<int> &in){
        if(!root) return;
        dfs(root->left, in);
        in.push_back(root->val);
        dfs(root->right, in);
    }
    
    void merge(vector<int> a1, vector<int> a2, vector<int> &ans){
        int i=0, j=0, k=0;
        while(i<a1.size() && j<a2.size()){
            if(a1[i]<a2[j]){
                ans[k++]=a1[i++];
            }
            else ans[k++]=a2[j++];
        }
        while(i<a1.size()){
            ans[k++]=a1[i++];
        }
        while(j<a2.size()){
            ans[k++]=a2[j++];
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        dfs(root1, arr1);
        dfs(root2, arr2);
        vector<int> merged(arr1.size()+arr2.size());
        merge(arr1, arr2, merged);
        return merged;
        
    }
};