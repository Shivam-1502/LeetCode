class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n - 1) % 2 == 1) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;

        const int INF = m + n;
        vector<vector<pair<int,int>>> dp(m, vector<pair<int,int>>(n, {INF, -1}));
        dp[0][0] = {1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int lo = INF, hi = -1;

                if (i > 0 && dp[i-1][j].second >= 0) {
                    lo = min(lo, dp[i-1][j].first);
                    hi = max(hi, dp[i-1][j].second);
                }
                if (j > 0 && dp[i][j-1].second >= 0) {
                    lo = min(lo, dp[i][j-1].first);
                    hi = max(hi, dp[i][j-1].second);
                }

                if (hi < 0) continue;

                int delta = (grid[i][j] == '(') ? 1 : -1;
                lo += delta;
                hi += delta;

                lo = max(lo, 0);
                int remaining = (m - 1 - i) + (n - 1 - j);
                hi = min(hi, remaining);

                if (lo > hi) continue;
                dp[i][j] = {lo, hi};
            }
        }

        return dp[m-1][n-1].first == 0;
    }
};