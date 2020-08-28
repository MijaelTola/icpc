#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        map<int,int> mp;
        mp[0] = 1e9;
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x]++;
            int df = x - 5;
            if(mp[df]) mp[df]--;
            else if(mp[df / 2] >= 2) {
                mp[df / 2] -= 2;
            } else flag = 0;
        }
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
            
    return 0;
}

