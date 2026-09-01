class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int,int>> litter;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));

        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') { sr = r; sc = c; }
                if (classroom[r][c] == 'L') {
                    litterIdx[r][c] = litter.size();
                    litter.push_back({r, c});
                }
            }

        int L = litter.size();
        int fullMask = (1 << L) - 1;

        if (L == 0) return 0;

        int E = energy;
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(E + 1,vector<bool>(1 << L, false))));

        queue<tuple<int,int,int,int>> q;

        int startEnergy = E;
        int startMask = 0;
        if (litterIdx[sr][sc] != -1)
            startMask |= (1 << litterIdx[sr][sc]);

        q.push({sr, sc, startEnergy, startMask});
        vis[sr][sc][startEnergy][startMask] = true;

        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, e, mask] = q.front(); q.pop();

                if (mask == fullMask) return moves;
                if (e == 0) continue;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (classroom[nr][nc] == 'X') continue;

                    int ne = e - 1;
                    if (classroom[nr][nc] == 'R') ne = E;

                    int nmask = mask;
                    if (litterIdx[nr][nc] != -1)
                        nmask |= (1 << litterIdx[nr][nc]);

                    if (!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};