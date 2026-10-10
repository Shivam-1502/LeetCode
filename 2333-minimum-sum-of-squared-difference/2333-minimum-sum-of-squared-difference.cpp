class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        unordered_map<int, int> freq;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            if (d > 0) freq[d]++;
            mx = max(mx, d);
        }

        while (k > 0 && mx > 0) {
            auto it = freq.find(mx);
            long long cnt = it->second;
            freq.erase(it);

            int nxt = mx - 1;
            while (nxt > 0 && !freq.count(nxt)) nxt--;

            long long cost = cnt * (mx - nxt);
            if (cost <= k) {
                k -= cost;
                freq[nxt] += cnt;
                mx = nxt;
            } else {
                long long q = k / cnt, r = k % cnt;
                if (mx - q - 1 >= 0) freq[mx - q - 1] += r;
                freq[mx - q] += cnt - r;
                k = 0;
            }
        }

        long long ans = 0;
        for (auto& [d, c] : freq) ans += (long long)d * d * c;
        return ans;
    }
};