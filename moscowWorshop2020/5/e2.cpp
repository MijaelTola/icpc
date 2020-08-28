#include <bits/stdc++.h>

using namespace std;

struct node{  
    int L, R, val;
};

vector<node> tree;
vector<int> root;

void build(int L, int R, int id) {
    if(L == R) {
        tree[id].val = 0;
    } else {
        int mid = (L + R) / 2;

        tree[id].L = tree.size();    
        tree.push_back((node){-1, -1, 0});
        build(L, mid, tree[id].L);

        tree[id].R = tree.size();    
        tree.push_back((node){-1, -1, 0});
        build(mid + 1, R, tree[id].R);

        tree[id].val = tree[tree[id].L].val + tree[tree[id].R].val;
    }
}

void update(int L, int R, int idx, int id_new, int id_old, int val) {
    if(L == R) {
        tree[id_new].val = val;
    } else {
        int mid = (L + R) / 2;
        if(idx <= mid) {
            tree[id_new].L = tree.size();
            tree[id_new].R = tree[id_old].R;
            tree.push_back((node){-1, -1, 0});
            update(L, mid, idx, tree[id_new].L, tree[id_old].L, val);
        } else {
            tree[id_new].L = tree[id_old].L;
            tree[id_new].R = tree.size();
            tree.push_back((node){-1, -1, 0});
            update(mid + 1, R, idx, tree[id_new].R, tree[id_old].R, val);
        }
    }
    tree[id_new].val = tree[tree[id_new].L].val + tree[tree[id_new].R].val; 
}

int query(int L, int R, int l, int r, int id) {
    if(L == l and R == r) {
        return tree[id].val;
    }
    int mid = (L + R) / 2;
    if(r <= mid) {
        return query(L, mid, l, r, tree[id].L);
    }
    if(l > mid) {
        return query(mid + 1, R, l, r, tree[id].R);
    }
    return query(L, mid, l, mid, tree[id].L) + 
        query(mid + 1, R, mid + 1, r, tree[id].R);
}

int a[100010];
int v[100010];

int main() {

    int n,m;
    cin >> n >> m;

    tree.clear(); root.clear();
    tree.push_back((node){-1, -1, 0});
    root.push_back(0);
    build(0, n - 1, 0);


    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = n - 1; i >= 0; i--) {
        root.push_back(tree.size());
        tree.push_back((node){-1, -1, 0});
        update(0, n - 1, a[v[i]], root[root.size() - 1], root[i - 1], 0);
        update(0, n - 1, i, root[root.size() - 1], root[i - 1], 1);
        a[v[i]] = i;
    }
    
    cout << "aca\n";
    reverse(root.begin(), root.end());

    int q;
    cin >> q;
    int p = 0;
    while(q--) {
        int x,y;
        cin >> x >> y;
        int l = (x + p) % n + 1;
        int k = (y + p) % m + 1;

        int a = -1, b = n + 1;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            int cnt = query(0, n - 1, 0, mid, root[l]);
            if(cnt >= k) b = mid;
            else a = mid;
        }
        cout << b << "\n";
        p = b;
    }

    return 0;
}

