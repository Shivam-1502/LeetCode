class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        int N = n + k - 1;
        int R = 2 * k;

        // Build Pascal's triangle up to N
        vector<vector<long long>> C(N+1, vector<long long>(N+1, 0));
        for (int i = 0; i <= N; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }

        return C[N][R];
    }
};