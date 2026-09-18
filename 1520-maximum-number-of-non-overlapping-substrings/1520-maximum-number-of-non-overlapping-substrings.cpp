class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c]  = max(last[c],  i);
        }

        auto getRight = [&](int i) -> int {
            int c = s[i] - 'a';
            int right = last[c];
            for (int j = i; j <= right; j++) {
                int d = s[j] - 'a';
                if (first[d] < i) return -1;
                right = max(right, last[d]);
            }
            return right;
        };

        vector<string> res;
        int curRight = -1;

        for (int i = 0; i < n; i++) {
            if (i != first[s[i] - 'a']) continue;

            int right = getRight(i);
            if (right == -1) continue;

            if (i > curRight) {
                res.push_back(s.substr(i, right - i + 1));
                curRight = right;
            } else if (right < curRight) {
                res.back() = s.substr(i, right - i + 1);
                curRight = right;
            }
        }

        return res;
    }
};