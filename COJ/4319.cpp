#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);

    while(v.size() < 10000) 
        v.push_back(v.back() + 3);

    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << v[x - 1] << "\n";
    }
    return 0;
}

