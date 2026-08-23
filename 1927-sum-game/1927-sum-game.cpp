class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int sumLeft = 0, sumRight = 0;
        int cntLeft = 0, cntRight = 0;

        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') cntLeft++;
            else sumLeft += num[i] - '0';
        }
        for (int i = half; i < n; ++i) {
            if (num[i] == '?') cntRight++;
            else sumRight += num[i] - '0';
        }

        return (2 * (sumLeft - sumRight) + 9 * (cntLeft - cntRight)) != 0;
    }
};