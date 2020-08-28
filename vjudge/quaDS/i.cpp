#include <bits/stdc++.h>

using namespace std;

int a[200010];
int b[200010];
int da[200010];
int db[200010];

struct segmentTree {
    int n;
    vector<int> st,pushdown, last;

    segmentTree(int _) {
        n = _;
        st.resize(3 * n);
        pushdown.resize(3 * n);
        last.resize(3 * n, -1);
    }
    
    void push(int node) {
        if(pushdown[node]) {
            last[2 * node] = last[2 * node + 1] = last[node];
            pushdown[2 * node] = pushdown[2 * node + 1] = 1;
            pushdown[node] = 0;
        }

    }

    void update(int node, int l, int r, int a, int b, int pos) {
        if (a <= l and r <= b) {
            last[node] = pos;
            pushdown[node] = 1;
            return;
        }
        push(node);
        int mid = (l + r) / 2;
        if(a <= mid) update(2 * node, l, mid, a, b, pos);
        if(b > mid) update(2 * node + 1, mid + 1, r, a, b, pos);
    }

    int query(int node, int l, int r, int pos) {
        if(l == r) return last[node];
        push(node);
        int mid = (l + r) / 2;
        if(pos <= mid) return query(2 * node, l, mid, pos);
        return query(2 * node + 1, mid + 1, r, pos);
    }
};


int main() {

    int n,m;
    scanf("%d %d", &n, &m);

    segmentTree st(n);

    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    
    for (int i = 0; i < m; ++i) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int x,y,k;
            scanf("%d %d %d", &x, &y, &k);
            x--,y--;
            st.update(1, 0, n, y, y + k - 1, i);
            da[i] = x;
            db[i] = y;
        } else {
            int x;
            scanf("%d", &x);
            x--;
            int last = st.query(1, 0, n, x);
            if(last == -1) printf("%d\n", b[x]);
            else printf("%d\n", a[da[last] + (x - db[last])]);
            
        }
    }
    return 0;
}

