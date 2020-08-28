#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    set<int> s;

    for (int i = 0; i < k; ++i) {
        int d;
        cin >> d;
        while(d--) {
            int x;
            cin >> x;
            s.insert(x);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i)
        ans += !s.count(i);

    cout << ans << "\n";
    return 0;
}

