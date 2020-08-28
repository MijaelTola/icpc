#include <bits/stdc++.h>

using namespace std;

int v[100010];
int a[31][100010];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < 31; ++i) {
        for (int j = 0; j < n; ++j) {
            if(v[j] & (1 << i)) a[i][j] = 1;
            if(j) a[i][j] += a[i][j - 1];
        }
    }

    while(q--) {
        int x,y; cin >> x >> y;
        x--,y--;
        long long ans = 0;

        int c1 = 0;
        int c0 = 0;
        for (int i = 0; i < 31; ++i) {
            int t1 = a[i][y] - a[i][x - 1];
            int total = y - x + 1;
            int t0 = total - t1;
            if(t0 > t1) ans ^= (1 << i), c1++;
            else c0++;
        }
        cout << ans << "\n";
    }
    return 0;
}
