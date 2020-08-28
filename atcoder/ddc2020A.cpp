#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

int main() {
    
    mp[1] = 300000;
    mp[2] = 200000;
    mp[3] = 100000;


    int a,b;
    cin >> a >> b;

    int ans = (a == 1 and b == 1) ? 400000 : 0;

    ans += mp[a] + mp[b];
    
    cout << ans  << "\n";

    return 0;
}

