class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());

        int pro1 = nums[n]*(nums[n-1])*(nums[n-2]);
        int pro2 = nums[0]*(nums[1])*(nums[n]);

        return max(pro1, pro2);
    }
};