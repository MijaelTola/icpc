#include <bits/stdc++.h>

using namespace std;

int main() {

    unsigned long long x,y;
    cin >> x >> y;

    if(y >= x) 
        return cout << y - x << "\n", 0;

    long long ans = 0;

    while(2 * x < y) {
        x *= 2;
        ans++;
    }
    
    long long a1 = y - x;
    long long a2 = 2 * x - y;

    cout << ans + min(a1, a2) << "\n";
    return 0;
}

