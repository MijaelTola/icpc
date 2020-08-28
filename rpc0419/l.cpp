#include <bits/stdc++.h>

using namespace std;

map<char,int> mp;
int main() {

    for (int i = 0; i < 5; ++i) {
        char x,y;
        cin >> x >> y;
        mp[x]++;
    }
    
    int ans = 0;
    for (auto p: mp) {
        ans = max(ans, p.second);
    }
    cout << ans << "\n";
    return 0;

}

