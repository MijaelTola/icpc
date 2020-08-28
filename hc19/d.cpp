#include <bits/stdc++.h>

using namespace std;

int p[65];
void init() {
    for (int i = 0; i < 65; ++i)
        p[i] = i;

}

int find(int x) {
    if(p[x] == x) return x;
    return find(p[x]);
}

bool merge(int x, int y, int z) {
    int px = find(x);
    int py = find(y);
    int pz = find(z);
    if(px == pz and pz == px and pz != x) return 0;
    if(py == pz and pz == py and py != y) return 0;
    p[px] = z;
    p[py] = z;
    return 1;
}

int main() {
    int t,n,m,x,y,z;
    cin >> t;
    while(t--) {
        init();
        cin >> n >> m;
        bool flag = 1;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            flag &= merge(x,y,z);
        }
        if(flag) {
            for (int i = 1; i <= n; ++i) {
                if(p[i] != i)cout << p[i] << " ";
                else cout << "0 ";
            }
            cout << "\n";
        } else cout << "impossible\n";
    }
    return 0;
}

