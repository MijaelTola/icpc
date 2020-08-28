#include <bits/stdc++.h>

using namespace std;

vector<int> v[20];
vector<int> f[20];
int ver[20];

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {

        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int a,b;
            cin >> a >> b;
            a--;
            if(b) v[i].push_back(a);
            else f[i].push_back(a);
        }
    }


    int ans = 0;
    for (int i = 1; i < (1 << t); ++i) {

        memset(ver, -1, sizeof ver);
        bool flag = 1;

        for (int j = 0; j < 16; ++j)
            if(i & (1 << j)) ver[j] = 1;
        
        
        for (int j = 0; j < 16; ++j) {
            if(i & (1 << j)) {
                for (int x: v[j]) {
                    if(ver[x] == -1) ver[x] = 1;
                    else if(ver[x] == 0) flag = 0;
                }
                for (int x: f[j]) {
                    if(ver[x] == -1) ver[x] = 0;
                    else if(ver[x] == 1) flag = 0;
                }

            } else {

                for (int x: v[j]) {
                    if(ver[x] == -1) ver[x] |= 0;
                    else if(ver[x] == 1) flag |= 0;
                }

                for (int x: f[j]) {
                    if(ver[x] == -1) ver[x] |= 1;
                    else if(ver[x] == 0) flag |= 0;
                }

            }
        }
        if(flag) ans = max(ans, __builtin_popcount(i));
    }

    cout << ans << "\n";
    return 0;
}

