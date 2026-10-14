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

    void inOrder(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        } 

        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);   
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>sorted;
        inOrder(root, sorted);

        return sorted[k-1];
    }
};