#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];

map<int,int> mp;

int main() {
    
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        mp[i - v[i]]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int val = v[i] + 1;
        int id = i + val;
        ans += mp[id - 1];
    }

    cout << ans << "\n";
    
    return 0;
}

