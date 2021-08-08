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

int n,m,id;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    vector<vector<int> > G(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    LCA lca(G,1);
   
    while(m--) {
        int a,b;
        cin >> a >> b;
        int u = lca.lca(a,b);
        
        int da = lca.height[a] - lca.height[u];
        int db = lca.height[b] - lca.height[u];
        int total = da + db + 1;

        //cout << u << ": " << da << " " << db << endl;
        auto C = [&] (long long u) {
            return (u * (u - 1)) / 2;
        };

        cout << n + C(total) << "\n";

        continue;
        int k;
        cin >> k;


        int mx = -1, id = -1;
        vector<int> q(k);

        for (int &x: q) {
            cin >> x;
            if(lca.height[x] > mx) {
                id = x;
                mx = lca.height[x];
            }
        }
        
        bool flag = 1;
        for (int &x: q) {
            int l = lca.lca(x, id);
            int d = abs(lca.height[x] - lca.height[l]);
            flag &= d <= 1;
        }

        puts(flag ? "YES" : "NO");
    }
    return 0;
}

