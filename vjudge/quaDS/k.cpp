#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;
struct tree {
	int n;
	int u[N], t[N];
	
	void init(int _n) {
		n = _n;
	}
    
    int left(int u) {
        return 2 * u;
    }

    int right(int u) {
        return 2 * u + 1;
    }
	void recalc(int x) {
		t[x] = max(t[left(x)], t[right(x)]);
	}

	void push(int x, int tl, int tr) {
		if (!u[x]) return;
		t[x] += u[x];
		if (tl < tr - 1) {
			u[left(x)] += u[x];
			u[right(x)] += u[x];
		}
		u[x] = 0;
	}

	
    void up(int ql, int qr, int d, int x, int tl, int tr) {
        push(x, tl, tr);
        if (qr <= tl || tr <= ql) return;
        if (ql <= tl && tr <= qr) {
            u[x] += d;
            push(x, tl, tr);
            return;
        }
        int mid = (tl + tr) >> 1;
        up(ql, qr, d, left(x), tl, mid);
        up(ql, qr, d, right(x), mid, tr);
        recalc(x);
    }

    void up(int ql, int qr, int d) {
        up(ql, qr, d, 1, 1, n + 1);
    }

    int g() {
        push(1, 1, n + 1);
        if (t[1] <= 0) return 0;
        for (int x = 1, tl = 1, tr = n + 1;;) {
            if (tl == tr - 1) return tl;
            int mid = (tl + tr) >> 1;
            push(left(x), tl, mid);
            push(right(x), mid, tr);
            if (t[right(x)] > 0)
                x = right(x), tl = mid;
            else	
                x = left(x), tr = mid;
        }
    }
} t;

int a[N];

int main () {
    int n;
    cin >> n;
    t.init(n);
    a[0] = -1;
    for (int i = 1; i <= n; ++i) {
        int ps, tp, x;
        cin >> ps >> tp;
        if (tp) {
            cin >> x;
            a[ps] = x;
        }
        else tp = -1;
        t.up(1, ps + 1, tp);           
        cout << a[t.g()] << "\n";
    }

    return 0;         	
}

