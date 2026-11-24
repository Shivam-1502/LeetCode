class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = nums[i], l = nums[i];
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, nums[j]);
                if (prod == (long long)g * l)
                    ans = max(ans, j - i + 1);
                if (prod > 25200LL) break;
            }
        }
        return ans;
    }
};