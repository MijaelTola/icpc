#include <bits/stdc++.h>

using namespace std;

int n,t;
int main() {
    cin >> n >> t;
    vector<int> v(n);
    int cnt = 0;
    for (int &x: v) {
        cin >> x;
        cnt += x <= 0;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        if(v[i] <= 0) {
            if (-v[i] <= t) {
                cur = cnt - i;
                ans = max(ans, cur);
            }
        }

        int left = t;
        if(v[i] <= 0) left = t + 2 * v[i];
        if(left <= 0) continue;
        int pos = upper_bound(v.begin(), v.end(), left) - v.begin() - 1;
        ans = max(ans,  cur + (pos - cnt + 1));
    }
    cout << ans << "\n";
    return 0;
}


