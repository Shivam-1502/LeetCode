class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<long long> v(n);
        for (int i = 0; i < n; i++)
            v[i] = abs(nums[i]);

        sort(v.begin(), v.end(), greater<long long>());

        int posCount = (n + 1) / 2;
        long long score = 0;

        for (int i = 0; i < n; i++) {
            if (i < posCount)
                score += v[i] * v[i];
            else
                score -= v[i] * v[i];
        }

        return score;
    }
};