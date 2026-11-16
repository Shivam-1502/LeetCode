class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            string newS = "";
            for(size_t i = 0; i < s.length(); i += k) {
                int sum = 0;
                for(size_t j = i; j < min(i+k, s.length()); ++j) {
                    sum += s[j] - '0';
                }
                newS += to_string(sum);
            }
            s = newS;
        }
        return s;
    }
};