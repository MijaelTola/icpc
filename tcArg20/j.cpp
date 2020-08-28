#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,d,a,b;
    cin >> n >> d >> a >> b;

    vector<pair<int,int> > v;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({1LL * x * a + 1LL * y * b, i});
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    vector<int> bb;

    for (int i = 0; i < n; ++i) {
        if(ans + v[i].first <= d) {
            ans += v[i].first;
            bb.push_back(v[i].second + 1);
        }
    }

    cout << bb.size() << "\n";
    for (auto x: bb)
        cout << x << " ";
    cout << "\n";

    return 0;
}

