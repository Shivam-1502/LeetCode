class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);

        vector<long long> dp(k, 0);

        for (int i = 0; i < n; i++) {
            int val = nums[i] % k;
            vector<long long> ndp(k, 0);
            for (int x = 0; x < k; x++) {
                if (dp[x] > 0) {
                    ndp[(1LL * x * val) % k] += dp[x];
                }
            }
            ndp[val]++;

            for (int x = 0; x < k; x++)
                result[x] += ndp[x];

            dp = ndp;
        }

        return result;
    }
};