#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x: v)
        cin >> x;

    int ans = -1;
    int mx = 0;
    for (int i = 2; i <= 1000; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if(v[j] % i == 0)cur++;
        }
        if(cur > mx) {
            mx = cur;
            ans = i;
        }
    }

    cout << ans << "\n";
    return 0;
}

