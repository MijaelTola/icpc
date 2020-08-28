#include <bits/stdc++.h>

using namespace std;

int p[100010];

void init() {
    for (int i = 0; i < 100010; ++i)
        p[i] = i;
}

int f(int x) {
    return x == p[x] ? x : p[x] = f(p[x]);
}

void merge(int x,int y) {
    p[f(y)] = p[f(x)];
}

int main() {
    int n,m;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        merge(x,y);
    }

    int ans = 0;

    
    for (int i = 1; i <= n; ++i)
        ans += f(i) == i;

    cout << ans << "\n";

    return 0;
}

