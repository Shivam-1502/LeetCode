class Solution {
    int log2_floor(int i) {
        return i ? 31 - __builtin_clz(i) : -1;
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        vector<pair<int, int>> P;
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (start == -1) start = i;
            } else {
                if (start != -1) {
                    P.push_back({start, i - 1});
                    start = -1;
                }
            }
        }
        if (start != -1) {
            P.push_back({start, n - 1});
        }

        int K = P.size();
        vector<int> V(K);
        for (int i = 0; i < K; i++) {
            V[i] = P[i].second - P[i].first + 1;
        }

        vector<int> W;
        if (K > 1) {
            W.resize(K - 1);
            for (int i = 0; i < K - 1; i++) {
                W[i] = V[i] + V[i + 1];
            }
        }

        vector<int> U;
        if (K > 1) {
            U.resize(K - 1);
            for (int i = 0; i < K - 1; i++) {
                U[i] = P[i + 1].first - P[i].second - 1;
            }
        }

        int max_log = K > 0 ? log2_floor(K) + 1 : 0;
        vector<vector<int>> st_V_max;
        if (K > 0) {
            st_V_max.assign(max_log, vector<int>(K));
            for (int i = 0; i < K; i++) st_V_max[0][i] = V[i];
            for (int j = 1; j < max_log; j++) {
                for (int i = 0; i + (1 << j) <= K; i++) {
                    st_V_max[j][i] = max(st_V_max[j - 1][i], st_V_max[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        vector<vector<int>> st_W_max, st_U_min;
        if (K > 1) {
            st_W_max.assign(max_log, vector<int>(K - 1));
            st_U_min.assign(max_log, vector<int>(K - 1));
            for (int i = 0; i < K - 1; i++) {
                st_W_max[0][i] = W[i];
                st_U_min[0][i] = U[i];
            }
            for (int j = 1; j < max_log; j++) {
                for (int i = 0; i + (1 << j) <= K - 1; i++) {
                    st_W_max[j][i] = max(st_W_max[j - 1][i], st_W_max[j - 1][i + (1 << (j - 1))]);
                    st_U_min[j][i] = min(st_U_min[j - 1][i], st_U_min[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        auto rmq_V_max = [&](int L, int R) {
            if (L > R) return 0;
            int j = log2_floor(R - L + 1);
            return max(st_V_max[j][L], st_V_max[j][R - (1 << j) + 1]);
        };
        auto rmq_W_max = [&](int L, int R) {
            if (L > R) return 0;
            int j = log2_floor(R - L + 1);
            return max(st_W_max[j][L], st_W_max[j][R - (1 << j) + 1]);
        };
        auto rmq_U_min = [&](int L, int R) {
            if (L > R) return static_cast<int>(1e9);
            int j = log2_floor(R - L + 1);
            return min(st_U_min[j][L], st_U_min[j][R - (1 << j) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            int a = -1, b = -1;
            int low = 0, high = K - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (P[mid].second >= l) {
                    a = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            low = 0; high = K - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (P[mid].first <= r) {
                    b = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (a == -1 || b == -1 || a >= b) {
                ans.push_back(total_ones);
                continue;
            }

            int Z1 = P[a].second - max(P[a].first, l) + 1;
            int Zm = min(P[b].second, r) - P[b].first + 1;
            
            int max_gain = 0;

            if (b == a + 1) {
                int Z_max = max(Z1, Zm);
                int O_min = U[a];
                int adj_max = Z1 + Zm;
                max_gain = max(adj_max, Z_max - O_min);
            } 
            else if (b == a + 2) {
                int Z_max = max({Z1, Zm, V[a + 1]});
                int O_min = min(U[a], U[a + 1]);
                int adj_max = max(Z1 + V[a + 1], V[a + 1] + Zm);
                max_gain = max(adj_max, Z_max - O_min);
            } 
            else {
                int Z_max = max({Z1, Zm, rmq_V_max(a + 1, b - 1)});
                int O_min = rmq_U_min(a, b - 1);
                int adj_max = max({Z1 + V[a + 1], V[b - 1] + Zm, rmq_W_max(a + 1, b - 2)});
                max_gain = max(adj_max, Z_max - O_min);
            }

            ans.push_back(total_ones + max_gain);
        }

        return ans;
    }
};