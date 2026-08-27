class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        for(int i = 0; i < k; ++i){
            currSum += nums[i];
        }
        double maxSum = currSum;
        for(int i = k; i < nums.size(); ++i){
            currSum += nums[i] - nums[i - k];
            if(currSum > maxSum) maxSum = currSum;
        }
        return maxSum / k;
    }
};