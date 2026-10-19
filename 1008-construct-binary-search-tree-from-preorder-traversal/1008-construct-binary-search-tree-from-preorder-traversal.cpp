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

    TreeNode* insert(TreeNode* root, int val){
        if(!root) return new TreeNode(val);

        TreeNode* node = root;
        while(true){
            if(val < node->val){
                if(!node->left){
                    node->left = new TreeNode(val);
                    break;
                }
                node = node->left;
            } else {
                if(!node->right){
                    node->right = new TreeNode(val);
                    break;
                }
                node = node->right;
            }
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for(int val : preorder){
            root = insert(root, val);
        }
        return root;
    }
};