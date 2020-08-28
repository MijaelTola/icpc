#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);  

    int n; cin >> n;

    long long mx = INT_MIN;
    long long mn = INT_MAX;

    while(n--) {
        long long x; cin >> x;
        mx = max(x,mx);
        mn = min(x,mn);
        cout << mn + mx << "\n";
    }
    return 0;
}

