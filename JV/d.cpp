#include <bits/stdc++.h>

using namespace std;


long long lcm(long long x, long long y) {
    return (x * y) / __gcd(x,y);
}
int main() {
    

    string x;
    cin >> x;
    
    long long ans = 300;
    for (int i = 0; i < (int)x.size(); ++i) {
        int cur = x[i] - '0';
        if(cur == 0) continue;
        ans = lcm(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}

