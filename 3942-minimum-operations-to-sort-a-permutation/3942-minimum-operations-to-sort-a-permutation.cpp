class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        
        bool inc = true;
        for (int i = 1; i < n; i++) {
            int prev = (zero + (i - 1)) % n;
            int curr = (zero + i) % n;
            if (nums[prev] > nums[curr]) {
                inc = false;
                break;
            }
        }
        
        bool dec = true;
        for (int i = 1; i < n; i++) {
            int prev = ((zero - (i - 1)) % n + n) % n;
            int curr = ((zero - i) % n + n) % n;
            if (nums[prev] > nums[curr]) {
                dec = false;
                break;
            }
        }
        
        int ans = INT_MAX;
        
        if (inc) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }
        
        if (dec) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
