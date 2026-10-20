class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int count = 0, temp = 0;
        // sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target){
                // ans.push_back(i);
                count++;
            }
            if(nums[i] == target){
                temp++;
            }
        }

        while(temp != 0){
            ans.push_back(count);
            count++;
            temp--;
        }

        return ans;
    }
};