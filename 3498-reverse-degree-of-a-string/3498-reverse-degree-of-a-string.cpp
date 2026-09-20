class Solution {
public:
    int reverseDegree(string s) {
        long long total = 0;
        for(int i = 0; i < s.length(); ++i){
            int revIdx = 'z' - s[i] + 1;
            total += revIdx * (i+1);
        }
        return total;
    }
};