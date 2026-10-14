class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        int nines     = sum / 9;
        int remainder = sum % 9;
        int zeros     = num - nines - (remainder > 0 ? 1 : 0);

        string ans = "";
        ans += string(nines, '9');
        if (remainder > 0)
            ans += (char)('0' + remainder);
        ans += string(zeros, '0');

        return ans;
    }
};