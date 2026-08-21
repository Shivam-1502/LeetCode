class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        long long hi = (long long)k * *min_element(coins.begin(), coins.end());

        vector<pair<long long, int>> subsets;
        subsets.reserve((1 << n) - 1);

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long lcm = 1;
            int bits = __builtin_popcount(mask);
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    lcm = lcm / __gcd(lcm, (long long)coins[i]) * coins[i];
                    if (lcm > hi) { overflow = true; break; }
                }
            }

            if (!overflow)
                subsets.push_back({lcm, (bits % 2 == 1) ? 1 : -1});
        }

        auto count = [&](long long x) -> long long {
            long long res = 0;
            for (auto& [lcm, sign] : subsets)
                res += sign * (x / lcm);
            return res;
        };

        long long lo = 1;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};