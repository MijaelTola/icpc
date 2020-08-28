#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;

    int cur = 0;
    bool first = 1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(cur + (int)s.size() <= k) {
            if(first) first = 0;
            else cout << " ";
            cout << s;
            cur += s.size();
        } else {
            cout << "\n" << s;
            cur = s.size();
        }
    }
    cout << "\n";
    return 0;
}

