class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int incLen = 1, decLen = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i]  > nums[i-1]){
                incLen++;
            } else {
                incLen = 1;
            }

            if(nums[i] < nums[i-1]){
                decLen++;
            } else {
                decLen = 1;
            }

            maxLen = max({maxLen, incLen, decLen});
        }
        return maxLen;
    }
};