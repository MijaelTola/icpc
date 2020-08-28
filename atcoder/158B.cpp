#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n,a,b;
    cin >> n >> a >> b;

    long long dv = n / (a + b);

    long long ans = dv * a;
    
    long long md = n % (a + b);
    if(md >= a) ans += a;
    else ans += md;
    cout << ans << "\n";
    return 0;
}

