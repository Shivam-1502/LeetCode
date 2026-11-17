class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int num : nums){
            int idx = abs(num) - 1;
            if(nums[idx] < 0) {
                ans.push_back(abs(num));
            } else {
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }
};