#include <bits/stdc++.h>

using namespace std;

bool v[100000010];
vector<int> b;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,x;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        b.push_back(x);
        v[x] = 1;
    }
    
    while(k--) {
        int y;
        cin >> y;
        int ans = 0;
        for (int x: b) {
            int l = y - x;
            if(l < 0 or l == x or l > 100000000) continue;
            if(v[x] and v[l]) ans++;
        }
        cout << y << " " << ans / 2 << "\n";
    }
    return 0;
}

