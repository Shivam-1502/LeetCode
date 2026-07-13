class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        vector<int> dp(n, 0);
        int pre;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int temp = dp[j];
                if(!i || !j || matrix[i][j] == '0'){
                    dp[j] = matrix[i][j] - '0';
                } else {
                    dp[j] = min({pre, dp[j], dp[j-1]}) + 1;
                }

                maxArea = max(maxArea, dp[j]);
                pre = temp;
            }
        }
        return maxArea * maxArea;
    }
};