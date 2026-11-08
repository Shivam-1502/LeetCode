class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    ++rowCount[r];
                    ++colCount[c];
                }
            }
        }
        
        int communicate = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1 && (rowCount[r] > 1 || colCount[c] > 1)) {
                    ++communicate;
                }
            }
        }
        
        return communicate;
    }
};