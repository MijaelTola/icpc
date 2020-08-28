#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        
        long long ans = b - a;
        
        int cnt = 0;
        while((a << 1) <= b) {
            cnt ++;
            a <<= 1;
            ans = min(ans, b - a + cnt);
        }
        cout << ans << "\n";

    }
    return 0;
}

