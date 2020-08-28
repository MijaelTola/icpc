#include <bits/stdc++.h>

using namespace std;


map<string,int> mp;
int main(){
    int m,n;
    cin >> m >> n;

    while(m--){
        string x; int y;
        cin >> x >> y;
        mp[x] = y;
    }

    while(n--){
        string x;
        int ans = 0;
        while(cin >> x and x != ".")
            ans += mp[x];
        cout << ans << "\n";
    }
    return 0;
}

