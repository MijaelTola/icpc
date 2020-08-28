#include <bits/stdc++.h>

using namespace std;

int n;
int v[1010];

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
        cin >> v[i];


    for (int i = 1; i <= n; ++i) {
        set<int> s;
        vector<int> ans;
        s.insert(i);
        ans.push_back(i);
        int cur = i;
        for (int j = 0; j < n; ++j) {
            int val = v[j] - cur;
            if(val <= 0) break;
            s.insert(val);
            ans.push_back(val);
            cur = val;
        }

        if((int)s.size() == n) {
            for (int j = 0; j < n; ++j) {
                cout << ans[j];
                if(j + 1 < n) cout << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    return 0;
}

