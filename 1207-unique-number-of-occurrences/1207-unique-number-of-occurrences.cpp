class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        unordered_set<int> frequencies;
        
        for (auto const& [num, count] : freqMap) {
            if (frequencies.count(count)) {
                return false;
            }
            frequencies.insert(count);
        }
        return true;
    }
};