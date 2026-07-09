class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, 
                                     vector<vector<int>>& queries) {
        vector<int> component_id(n);
        int current_component = 0;
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i-1] > maxDiff) {
                current_component++;
            }
            component_id[i] = current_component;
        }
        
        vector<bool> result;
        for (const auto& q : queries) {
            result.push_back(component_id[q[0]] == component_id[q[1]]);
        }
        
        return result;
    }
};