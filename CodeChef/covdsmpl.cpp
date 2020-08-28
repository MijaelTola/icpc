#include <bits/stdc++.h>

using namespace std;

int n,p;
int ans[65][65];

int query(int a, int b, int c, int d) {
    cout << "1 " << a << " " << b << " " << c << " " << d << endl;
    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

void f(int id, int l, int r, int cnt) {
    if(l == r) {
        ans[id][l] = cnt;
        return;
    }

    if(cnt == r - l + 1) {
        for (int i = l; i <= r; ++i)
            ans[id][i] = 1;
        return;
    }

    int mid = (l + r) / 2;

    int x = query(id, l, id, mid);
    if(x) f(id, l, mid, x);
    if(cnt - x > 0) f(id, mid + 1, r, cnt - x);
}

void F(int l, int r, int cnt) {
    if(l == r) {
        f(l, 1, n, cnt);
        return;
    }

    if((r - l + 1) * n == cnt) {
        for (int i = l; i <= r; ++i) 
            for (int j = 1; j <= n; ++j)
                ans[i][j] = 1;
        return;
    }
    int mid = (l + r) / 2;
    int x = query(l, 1, mid, n);
    if(x) F(l, mid, x);
    if(cnt - x > 0) F(mid + 1, r, cnt - x);
}

int main() {

    int t;

    cin >> t;

    while(t--) {
    	memset(ans, 0, sizeof ans);
        cin >> n >> p;
        
        int x = query(1, 1, n, n);
        if(x) F(1, n, x);
        cout << 2 << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) 
                cout << ans[i][j] << " ";
            cout << "\n";
        }
        cout << endl;
        
        cin >> x;
        if(x == -1) return 0;
    }
    return 0;
}

