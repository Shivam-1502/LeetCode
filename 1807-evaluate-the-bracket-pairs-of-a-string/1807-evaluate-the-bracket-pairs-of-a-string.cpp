class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& kv : knowledge)
            dict[kv[0]] = kv[1];

        string ans;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = s.find(')', i + 1);
                string key = s.substr(i + 1, j - i - 1);
                ans += dict.count(key) ? dict[key] : "?";
                i = j;
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};