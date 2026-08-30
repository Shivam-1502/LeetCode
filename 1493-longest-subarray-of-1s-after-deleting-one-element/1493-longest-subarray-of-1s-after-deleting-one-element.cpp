class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, zeros = 0, ans = 0;

        for (int r = 0; r < (int)nums.size(); ++r) {
            if (nums[r] == 0) zeros++;

            while (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            ans = max(ans, r - l);
        }

        return ans;
    }
};