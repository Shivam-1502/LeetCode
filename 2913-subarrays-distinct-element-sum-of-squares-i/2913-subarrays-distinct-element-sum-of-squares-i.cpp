class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            unordered_set<int> ele;
            for(int j = i; j < nums.size(); ++j){
                ele.insert(nums[j]);
                sum += ele.size()*ele.size();
            }
        }
        return sum;
    }
};