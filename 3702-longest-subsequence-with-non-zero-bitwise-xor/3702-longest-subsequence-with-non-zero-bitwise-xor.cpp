class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        bool hasNonZero = false;

        for(int num : nums){
            sum  ^= num;
            if(num != 0) hasNonZero  = true;
        }

        if(sum != 0) return n;
        if(!hasNonZero) return 0;

        return n - 1;
    }
};