class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0);
        vector<int> sz(n, 1), heavy(n, -1);
        vector<int> head(n), pos(n);
        vector<int> order;

        order.push_back(0);

        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            int best = 0;

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                sz[u] += sz[v];

                if (sz[v] > best) {
                    best = sz[v];
                    heavy[u] = v;
                }
            }
        }

        int timer = 0;

        for (int u : order) {
            if (parent[u] != -1 && heavy[parent[u]] == u)
                continue;

            for (int v = u; v != -1; v = heavy[v]) {
                head[v] = u;
                pos[v] = timer++;
            }
        }

        int size = 1;
        while (size < n) size <<= 1;

        vector<int> seg(2 * size, 0);

        for (int i = 0; i < n; i++) {
            seg[size + pos[i]] = 1 << (s[i] - 'a');
        }

        for (int i = size - 1; i > 0; i--) {
            seg[i] = seg[i << 1] ^ seg[i << 1 | 1];
        }

        auto update = [&](int u, char c) {
            int p = size + pos[u];
            seg[p] = 1 << (c - 'a');

            while (p > 1) {
                p >>= 1;
                seg[p] = seg[p << 1] ^ seg[p << 1 | 1];
            }

            s[u] = c;
        };

        auto rangeQuery = [&](int l, int r) {
            int result = 0;

            l += size;
            r += size;

            while (l <= r) {
                if (l & 1) result ^= seg[l++];
                if (!(r & 1)) result ^= seg[r--];

                l >>= 1;
                r >>= 1;
            }

            return result;
        };

        auto pathQuery = [&](int u, int v) {
            int mask = 0;

            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);

                mask ^= rangeQuery(pos[head[u]], pos[u]);
                u = parent[head[u]];
            }

            if (depth[u] > depth[v])
                swap(u, v);

            mask ^= rangeQuery(pos[u], pos[v]);

            return (mask & (mask - 1)) == 0;
        };

        vector<bool> answer;

        for (const string &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                update(u, c);
            } else {
                int v;
                ss >> v;
                answer.push_back(pathQuery(u, v));
            }
        }

        return answer;
    }
};