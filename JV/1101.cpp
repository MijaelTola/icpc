#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long x,y;
        cin >>  x >> y;
        long long ans = 0;
        while(true){
            long long cur  = x / y;
            ans += cur;
            if(!(x % y)) break;
            long long sz = x -  y * cur;
            x = y;
            y = sz;
        }
        cout << ans << "\n";
    }
    return 0;
}

