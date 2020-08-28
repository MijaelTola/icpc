#include <bits/stdc++.h>

using namespace std;

long long v[2000][3];
int main() {
    
    memset(v, 0, sizeof v);
    v[0][0] = 1;
    
    int ms = 0;
    int type = 0;
    while(ms <= 1600) {
        if(type == 0) {
            ms += 2;
            v[ms][1] = v[ms - 2][0];
            type = 1;
            continue;
        }
        if(type == 1) {
            ms += 8;
            v[ms][2] = v[ms - 8][1];
            type = 2;
            continue;
        }
        if(type == 2) {
            ms += 16;
            v[ms][0] = 2 * v[ms - 16][2];
            type = 0;
            continue;
        }
    }
    
    for (int i = 0; i <= 1600; ++i) {
        if(v[i][1] or v[i][0] or v[i][2]) continue;
        v[i][0] = v[i - 1][0];
        v[i][1] = v[i - 1][1];
        v[i][2] = v[i - 1][2];
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        n--;
        cout << v[n][0] << " " << v[n][1] << " " << v[n][2] << "\n";
    }
    return 0;
}
