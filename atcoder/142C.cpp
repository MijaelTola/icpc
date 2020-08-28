#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back({x, i + 1});
    }
    
    sort(v.begin(), v.end());

    for (auto p: v)
        cout << p.second << " ";
    cout << "\n";
    return 0;
}

