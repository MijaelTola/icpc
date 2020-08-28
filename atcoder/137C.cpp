#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    map<string,long long> mp;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    
    long long ans = 0;
    for (auto p: mp) 
        ans += (p.second * (p.second - 1)) / 2;
    
    cout << ans << "\n";
    return 0;
}

