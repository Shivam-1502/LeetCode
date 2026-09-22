class Solution {
public:
    static const int MAXK = 5;

    struct Node {
        int prod;
        int cnt[MAXK];
        Node() : prod(1) { memset(cnt, 0, sizeof(cnt)); }
    };

    int K, N;
    vector<Node> tr;

    inline void merge(Node& dst, const Node& a, const Node& b) {
        dst.prod = (int)((long long)a.prod * b.prod % K);
        memcpy(dst.cnt, a.cnt, sizeof(int) * K);
        for (int r = 0; r < K; r++) {
            if (b.cnt[r]){
                dst.cnt[(long long)a.prod * r % K] += b.cnt[r];
            }
        }
    }

    void build(int u, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % K;
            tr[u].prod = v;
            memset(tr[u].cnt, 0, sizeof(int) * K);
            tr[u].cnt[v] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(2*u, l, mid, nums);
        build(2*u+1, mid+1, r, nums);
        merge(tr[u], tr[2*u], tr[2*u+1]);
    }

    void update(int u, int l, int r, int pos, int val) {
        if (l == r) {
            int v = val % K;
            tr[u].prod = v;
            memset(tr[u].cnt, 0, sizeof(int) * K);
            tr[u].cnt[v] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*u, l, mid, pos, val);
        else update(2*u+1, mid+1, r, pos, val);
        merge(tr[u], tr[2*u], tr[2*u+1]);
    }

    void query(int u, int l, int r, int ql, int qr, Node& res, bool& first) {
        if (ql <= l && r <= qr) {
            if (first){
                res = tr[u]; first = false;
            } else {
                Node tmp;
                merge(tmp, res, tr[u]);
                res = tmp;
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) query(2*u, l, mid, ql, qr, res, first);
        if (qr > mid) query(2*u+1, mid+1, r, ql, qr, res, first);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k; N = nums.size();
        tr.resize(4 * N);
        build(1, 0, N-1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, N-1, idx, val);
            Node res;
            bool first = true;
            query(1, 0, N-1, start, N-1, res, first);
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};