class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = 4e18;
        vector<long long> dp(n+1, INF);
        dp[0] = 0;
        for(int i = 0; i < n; ++i) {
            if(dp[i] == INF) continue;
            for(int j = i+1; j <= min(i+3, n); ++j) {
                long long d = j - i;
                dp[j] = min(dp[j], dp[i] + costs[j-1] + d*d);
            }
        }
        return dp[n];
    }
};