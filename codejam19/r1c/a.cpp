#include <bits/stdc++.h>

using namespace std;

string v[256];
char c[3] = {'R','P','S'};
int n;
int check(char x, char y) {
    if(x == y) return 2;
    if(x == 'R' and y == 'S') return 1;
    if(x == 'R' and y == 'P') return 0;
    if(x == 'S' and y == 'P') return 1;
    if(x == 'S' and y == 'R') return 0;
    if(x == 'P' and y == 'R') return 1;
    if(x == 'P' and y == 'S') return 0;
    return 0;
}

int ver(string y) {
    for (int i = 0; i < 3; ++i) {
        if(!check(c[i], y[0])) continue;
        y += c[i];
        bool can = 1;
        for (int j = 0; j < n; ++j) {
            int mx = max(y.size(), v[j].size());
            bool win = 0;
            for (int k = 0; k < 2 * mx; ++k) {
                int val = check(y[k % y.size()], v[j][k % v[j].size()]);
                if(val == 0) break;
                if(val == 1) {
                    win = 1;
                    break;
                }
            }
            can &= win;
        }
        if(can == 1) 
            return i; 
        y.pop_back();
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    int k = 1;
    reset:
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        cout << "Case#" << k++ << ": ";
        for (int i = 0; i < n; ++i) {
            int val = ver(v[i]);
            if(val != -1) {
                cout << v[i] + c[val] << "\n";
                goto reset;
            }
        }
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}

