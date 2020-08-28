#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        set<int> s;
        int n; cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            s.insert(v[i]);
        }
        sort(v, v + n);
        int ans = 0;
        int p = 0;
        while((int)s.size() < n) {
            if(s.count(v[p] + v[n - 1])) p++;
            else {
                v[n - 1] += v[p];
                s.insert(v[n - 1]);
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

