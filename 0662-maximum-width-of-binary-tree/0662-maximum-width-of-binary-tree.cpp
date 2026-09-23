class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWid = 0;

        while(q.size() > 0){
            int currLevSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWid = max(maxWid, (int)(endIdx - stIdx + 1));
            for(int i = 0; i < currLevSize; i++){
                auto curr = q.front();
                q.pop();

                if(curr.first->left){
                    q.push({curr.first->left, curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, curr.second*2+2});
                }
            }
        }
        return maxWid;
    }
};