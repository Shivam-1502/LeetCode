class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[nums[i]].push_back(i);
        }
        
        int ans = -1;
        int maxWindowStart = n - k;
        
        for (auto& [num, indices] : positions) {
            vector<pair<int, int>> intervals;
            for (int idx : indices) {
                int L = max(0, idx - k + 1);
                int R = min(maxWindowStart, idx);
                if (L <= R) {
                    intervals.push_back({L, R});
                }
            }
            
            if (intervals.empty()) continue;
            
            sort(intervals.begin(), intervals.end());
            
            int uniqueCount = 0;
            int currentStart = intervals[0].first;
            int currentEnd = intervals[0].second;
            
            for (size_t i = 1; i < intervals.size(); ++i) {
                if (intervals[i].first <= currentEnd + 1) {
                    currentEnd = max(currentEnd, intervals[i].second);
                } else {
                    uniqueCount += (currentEnd - currentStart + 1);
                    currentStart = intervals[i].first;
                    currentEnd = intervals[i].second;
                }
            }
            uniqueCount += (currentEnd - currentStart + 1);
            
            if (uniqueCount == 1) {
                ans = max(ans, num);
            }
        }
        
        return ans;
    }
};