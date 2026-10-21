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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;
    void inOrder(TreeNode* root){
        if(root == NULL){
            return;
        }

        inOrder(root->left);
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
            }
            sec = root;
        }
        prev = root;
        inOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inOrder(root);

        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;
    }
};