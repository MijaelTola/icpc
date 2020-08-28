#include <bits/stdc++.h>

using namespace std;

int v[1000010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);   
    int t; cin >> t;
    while(t--) {
        
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) 
            ans ^= (v[i] + v[i]);
        cout << ans << "\n";
    }
    return 0;
}

