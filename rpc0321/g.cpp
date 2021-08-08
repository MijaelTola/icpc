#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[200010];
int b[200010];
int c[200010];

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x,y;
        cin >> x >> y;
        a[x] = y;
    }

    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i) {
        c[i] = a[i] - b[i];
    }

    vector<pair<int,int> > v;

    for (int i = 1; i <= n; ++i) {
        if(a[i]) v.push_back({c[i], i});
    }

    sort(v.begin(), v.end());
    
    int total = 0;

    for (int i = 1; i <= n; ++i) {
        total += b[i];
    }
    bool needed = 1;
    for (auto p: v) {
        int cost = b[p.second];
        cout << total - cost << "\n";
        if(needed or cost > a[p.second]) {
            //cout << p.second << " este de aca se borra\n";
            needed = 0;
            total = total - cost + a[p.second];
        }
    }

    cout << total << "\n";


    return 0;
}

