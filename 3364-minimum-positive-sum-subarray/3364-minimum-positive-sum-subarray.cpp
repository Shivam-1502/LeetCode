class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int s = 0;
            for (int j = i; j < min((int)nums.size(), i + r); j++) {
                s += nums[j];
                if (j - i + 1 >= l && s > 0){
                    ans = min(ans, s);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};