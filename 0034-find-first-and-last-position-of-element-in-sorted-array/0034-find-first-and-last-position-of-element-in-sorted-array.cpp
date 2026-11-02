class Solution {
public:

    int lowerBound(const vector<int>& nums, int t) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < t) lo = mid + 1;
            else               hi = mid;
        }
        return lo;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        if (start == (int)nums.size() || nums[start] != target) return {-1, -1};
        int end = lowerBound(nums, target + 1) - 1;
        
        return {start, end};
    }
};