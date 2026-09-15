class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // Phase 1: precompute palindrome table
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) isPalin[i][i] = true;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    isPalin[i][j] = (len == 2) ? true : isPalin[i+1][j-1];
            }
        }

        // Phase 2: 1D DP
        vector<int> dp(n + 1, 0);

        for (int i = k - 1; i < n; i++) {
            dp[i + 1] = dp[i];

            for (int len = k; len <= k + 1; len++) {
                int j = i - len + 1;
                if (j >= 0 && isPalin[j][i]) {
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};