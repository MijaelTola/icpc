#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    map<string,int > mp;

    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        mp[x]++;
    }
    
    int mx = 0;
    for (auto p: mp) {
        mx = max(p.second, mx);
    }

    for (auto p: mp) 
        if(mx == p.second) cout << p.first << "\n";
    return 0;
}

