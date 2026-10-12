class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        const int BITS = 30;

        vector<int> cnt(BITS, 0);
        for (int x : nums){
            for (int i = 0; i < BITS; i++){
                if (x >> i & 1) cnt[i]++;
            }
        }

        long long ans = 0;
        for (int t = 0; t < k; t++) {
            long long num = 0;
            for (int i = 0; i < BITS; i++) {
                if (cnt[i] > 0) {
                    num |= (1LL << i);
                    cnt[i]--;
                }
            }
            ans = (ans + num % MOD * (num % MOD)) % MOD;
        }

        return (int)ans;
    }
};