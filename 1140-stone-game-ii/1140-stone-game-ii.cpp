class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        vector<int> suffix(n+1);
        for(int i = n-1; i >= 0; --i){
            suffix[i] = suffix[i + 1] + piles[i];
        }

        for(int i = n-1; i >= 0; --i){
            dp[i][n-i] = suffix[i];
        }

        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 1; --j){
                for(int k = 1; k <= 2*j && i+k <= n; ++k){
                    dp[i][j] = max(dp[i][j], suffix[i] - dp[i+k][max(j, k)]);
                }
            }
        }
        return dp[0][1];
    }
};