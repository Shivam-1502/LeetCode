class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for (int v : nums) total += v;

        int target = total - x;

        if (target == 0) return n;
        if (target < 0) return -1;

        int maxLen = -1;
        int curr = 0, left = 0;

        for (int right = 0; right < n; right++) {
            curr += nums[right];

            while (curr > target){
                curr -= nums[left++];
            }

            if (curr == target)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};