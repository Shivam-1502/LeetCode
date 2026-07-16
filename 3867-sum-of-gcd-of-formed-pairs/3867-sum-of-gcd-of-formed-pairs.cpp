class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0, n = nums.size();
        vector<int> g(n);

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            g[i] = gcd(nums[i], mx);
        }

        sort(g.begin(), g.end());
        long long sum = 0;
        for(int i = 0, j = n - 1; i < n / 2; i++, j--){
            sum += gcd(g[i], g[j]);
        }
        return sum;
    }
};