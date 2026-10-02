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

    void inOrder(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        } 

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);   
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> sorted;
        inOrder(root, sorted);
        int n = sorted.size();
        int diff = INT_MAX;

        for(int i = 1; i < n; i++){
            diff = min(diff, sorted[i] - sorted[i-1]);
        }

        return diff;
    }
};