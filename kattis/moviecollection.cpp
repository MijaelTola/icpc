#include <bits/stdc++.h>

using namespace std;

int p[300010];
int st[2 * 300010];
int n,q;

void update(int pos, int value) {
    for (st[pos += n] = value; pos > 1; pos >>= 1)
        st[pos >> 1] = st[pos] + st[pos ^ 1];
}

int query(int l, int r) {
    int ans = 0;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) ans += st[l++];
        if(r & 1) ans += st[--r];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        memset(st, 0, sizeof st);
        memset(p, 0, sizeof p);
        cin >> n >> q;
        int pos = 200000;
        for (int i = 1; i <= n; ++i) {
            p[i] = i + pos;
            update(p[i], 1);
        }

        int left = pos - 1;
        while(q--) {
            int x; cin >> x;
            int pp = p[x];
            cout << query(left, pp - 1) << " ";
            update(pp, 0);
            update(--left, 1);
            p[x] = left;
        }
        cout << "\n";
    }
    return 0;
}

