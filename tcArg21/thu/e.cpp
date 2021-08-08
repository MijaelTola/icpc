#include <bits/stdc++.h>

using namespace std;

set<int> s;
int v[2000010];
int mx[2000010];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        v[x] = 1;
        mx[x] = x;
    }

    int cur = 0;
    for (int i = 0; i < 2000010; ++i) {
        cur = max(cur, mx[i]);
        mx[i] = cur;
    }

    int ans = 0;

    for (int i = 2; i < 2000010; ++i) {
        if(!v[i]) continue;
        for (int j = i + i; j < 2000010; j += i) {
            int val = mx[j - 1];
            if(val > i and val >= i - j) {
                ans = max(ans, val % i);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

