class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        
        unordered_set<double> disAvg;

        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            double avg = (nums[left] + nums[right]) / 2.0;
            disAvg.insert(avg);
            left++;
            right--;
        }
        return *min_element(disAvg.begin(), disAvg.end());
    }
};