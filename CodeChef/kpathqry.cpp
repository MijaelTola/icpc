#include <bits/stdc++.h>

using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

int n;
int main() {

    //ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<vector<int> > G(n + 10);
        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        LCA lca(G,1);

        int q;
        cin >> q;

        while(q--) {
            int k;
            cin >> k;
            vector<int> v;
            int id = -1;
            int mx = -1;
            for (int i = 0; i < k; ++i) {
                int x;
                cin >> x;
                v.push_back(x);
                if(lca.height[x] > mx) {
                    mx = lca.height[x];
                    id = x;
                }
            }

            int last = v[0];
            for (int i = 1; i < k; ++i) {
                int l = lca.lca(id, v[i]);
                if(lca.height[l] < mx) {
                    last = l;
                    mx = lca.height[l];
                }
                last = lca.lca(last, v[i]);
            }
            
            int flag = 1;
            for (int i = 1; i < k; ++i) {
                int l = lca.lca(v[i - 1], v[i]);
                flag &= (l == last or l == v[i - 1] or l == v[i]);
            }

            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }

    }


    return 0;
}

