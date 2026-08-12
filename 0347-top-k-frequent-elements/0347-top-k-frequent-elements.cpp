class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int& i : nums) ++freq[i];

        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>> q;

        for(auto& [key, val] : freq){
            q.push({val, key});
            if(q.size() > k) q.pop();
        }

        vector<int> ans;
        ans.reserve(k);
        while(!q.empty()){
            ans.emplace_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};