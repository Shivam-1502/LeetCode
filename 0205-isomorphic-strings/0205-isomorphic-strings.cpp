class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (sToT.count(c1)) {
                if (sToT[c1] != c2) return false;
            } else {
                sToT[c1] = c2;
            }

            if (tToS.count(c2)) {
                if (tToS[c2] != c1) return false;
            } else {
                tToS[c2] = c1;
            }
        }

        return true;
    }
};