#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m,t;
    cin >> n >> m >> t;

    int ini = 0;
    bool flag = 1;
    int dn = n;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        int dis = (a - ini);
        n -= dis;
        flag &= n > 0;

        dis = (b - a);
        n += dis;
        n = min(dn, n);
        ini = b;
    }

    int dis = (t - ini);
    n -= dis;
    flag &= n > 0;

    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

