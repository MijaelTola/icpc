#include <bits/stdc++.h>

using namespace std;

int last[2000010];
int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    long long ans = 0;

    last[0] = -1;
    for (int i = 1; i < n; ++i) {
        int cur = 0;
        int id = i - 1;
        while(id != -1 and v[id] <= v[i]) {
            id = last[id];
            if(id + 1 != i and id != -1) {
                cur++;
            }
        }
        last[i] = id;
        ans += cur;
    }

    ans += (n - 1);

    cout << ans << "\n";
    return 0;
}
