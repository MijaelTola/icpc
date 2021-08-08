#include <bits/stdc++.h>

using namespace std;

vector<int> c[100010];
int main() {

    int n;
    cin >> n;

    map<int, vector<int> > mp;

    vector<int> a,b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        a.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        b.push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        c[b[x]].push_back(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        ans += c[x].size();
    }

    cout << ans << "\n";


    return 0;
}

