#include <bits/stdc++.h>

using namespace std;

int T,n,t;
char m;
int c[5][20];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long ans = 0;

    cin >> T;

    while(T--) {
        memset(c, 0, sizeof c);
        char v[] = {'A','B','C', 'D'};
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m >> t;
            c[m - 'A'][t]++;
        }
        int mx = -1e9;
        do {
            int tt[] = {3, 6, 9 , 12};
            do {
                int p [] = {25, 50, 75, 100};
                do {
                    int cur = 0;
                    for (int i = 0; i < 4; ++i) {
                        int val = c[v[i] - 'A'][tt[i]] * p[i];
                        if(val == 0)  cur -= 100;
                        else cur += val;
                    }
                    mx = max(mx, cur);
                } while(next_permutation(p, p + 4));
            } while(next_permutation(tt, tt + 4));
        } while(next_permutation(v, v + 4));
        cout << mx << "\n";
        ans += mx;
    }
    cout << ans << "\n";
    return 0;
}

