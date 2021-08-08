#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long double r,x,y;
    cin >> r >> x >> y;

    long double dis = sqrt(x * x + y * y);
    
    if(r > dis) return cout << "2\n", 0;
    long long ans = dis / r;
    if(fmod(dis, r) != 0) ans++;
    cout << ans << endl;
    return 0;
}

