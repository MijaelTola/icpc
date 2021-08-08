#include <bits/stdc++.h>

using namespace std;

int ans[100010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        map<int, vector<int> > mp;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
        
        int pos = 100000;
        for (auto [x, v]: mp) {
            for (auto p: v) {
                ans[p] = pos;
            }
            pos++;
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";

    }
    return 0;
}

