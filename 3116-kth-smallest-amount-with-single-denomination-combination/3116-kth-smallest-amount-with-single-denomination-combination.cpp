class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        long long lo = *min_element(coins.begin(), coins.end());
        long long hi = (long long)k * lo;  // FIX 1 — see below

        vector<vector<long long>> subsets(n + 1);  // FIX 2 — see below

        function<void(long long, int, int)> build = [&](long long val, int setNumber, int idx) {
            val = lcm(val, (long long)coins[idx]);
            if (val > hi) return;

            subsets[setNumber].push_back(val);
            for (int i = idx + 1; i < n; ++i)
                build(val, setNumber + 1, i);
        };

        for (int i = 0; i < n; ++i)
            build(1, 1, i);

        auto getRank = [&](long long value) -> long long {
            long long rank = 0;
            for (int i = 1; i <= n; ++i)
                for (long long lcmVal : subsets[i])
                    if (i % 2 != 0) rank += value / lcmVal;
                    else             rank -= value / lcmVal;
            return rank;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (getRank(mid) >= k) hi = mid;
            else                   lo = mid + 1;
        }
        return lo;
    }
};