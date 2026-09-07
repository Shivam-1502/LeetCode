class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> last(26, 0);
        long long sum = 0;

        for(char c : s){
            int x = c - 'a';

            long long newSum = (2* sum + 1 - last[x] + MOD) % MOD;
            last[x] = sum + 1;
            sum = newSum;
        }
        return sum;
    }
};