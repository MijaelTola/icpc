#include <bits/stdc++.h>

using namespace std;


int v[100010];
set<int> s;


int main() {

    int n,l,x,y;
    cin >> n >> l >> x >> y;
    bool f = 0, f2 = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        v[i] = m;
        s.insert(m);
        f |= m == x;
        f2 |= m == y;
    }

    set<int> s2 = s;
    if(s.count(x) and s.count(y)) return cout << "0\n",0;
    f = 0, f2 = 0;
    for (int p: s) {
        if(p >= x) {
            if(s.count(p - x) and s.count(p + y))
                return cout << "0\n",0;
        }
        if(s.count(p + x)) f = 1;
        if(s.count(p + y)) f2 = 1;
    }

    if(f and f2)
        return cout << "0\n", 0;

    s.insert(x);
    s.insert(y);


    for (int i = 0; i < n; ++i) {
        if(v[i] >= x) 
            s.insert(v[i] - x);
        if(v[i] >= y)
            s.insert(v[i] - y);
        if(v[i] + x <= l) 
            s.insert(v[i] + x);

        if(v[i] + y <= l)
            s.insert(v[i] + y);
    }

    for (int p: s) {
        if(s2.count(p - x) and s2.count(p + y))
            return cout << "1\n" << p << "\n", 0;

        if(s2.count(p - x) and s2.count(p - y))
            return cout << "1\n" << p << "\n", 0;

        if(s2.count(p + x) and s2.count(p + y))
            return cout << "1\n" << p << "\n", 0;

        if(s2.count(p + x) and s2.count(p - y))
            return cout << "1\n" << p << "\n", 0;
    }

    int a = - 1,b = -1;

    for (int p: s) {
        if(p >= x and s.count(p - x)) {
            a = p;
            break;
        }
    }

    for (int p: s) {
        if(p >= y and s.count(p - y)) {
            b = p;
            break;
        }
    }

    if(f) cout << "1\n" << b << "\n";
    else if(f2) cout << "1\n" << a << "\n";
    else cout << "2\n" << a << " " << b << "\n";

    return 0;
}

