class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int L = 0b0000011110;
        const int M = 0b0001111000; 
        const int R = 0b0111100000; 

        unordered_map<int, int> rowMask;
        for (auto& s : reservedSeats)
            rowMask[s[0]] |= (1 << (s[1] - 1));

        int ans = 2 * n;
        for (auto& [row, mask] : rowMask) {
            ans -= 2;

            bool canL = (mask & L) == 0;
            bool canM = (mask & M) == 0;
            bool canR = (mask & R) == 0;

            if (canL && canR)
                ans += 2;  
            else if (canL || canM || canR)
                ans += 1;
        }

        return ans;
    }
};