#include <bits/stdc++.h>

using namespace std;

vector<int> v[200010];
int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n; 

    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(v[i].begin(), v[i].end());
        cout << v[i][1];
        if(i + 1 < n) cout << " ";
    }
    cout << "\n";

    return 0;
}

