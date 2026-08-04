class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int maxEle = *max_element(nums.begin(), nums.end());

        vector<bool> exists(maxEle - minEle + 1);
        for(int& num : nums){
            exists[num - minEle] = true;
        }

        vector<int> ans;
        for(int i = 0; i < maxEle-minEle; ++i){
            if(!exists[i]){
                ans.push_back(i + minEle);
            }
        }

        return ans;
    }
};