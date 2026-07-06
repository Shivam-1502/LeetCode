class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](vector<int>& x) {
            return pair{x[0], -x[1]};
        });

        int count = 0;
        int maxEnd = 0;

        for(vector<int>& interval : intervals){
            if(interval[1] > maxEnd){
                ++count;
                maxEnd = interval[1];
            }
        }
        return count;
    }
};