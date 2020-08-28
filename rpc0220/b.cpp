#include <bits/stdc++.h>

using namespace std;

int main() {

    long long x;
    cin >> x;

    long long x2 = x;
    long long cur = 1;

    while(x > 10) {
        cur *= 10;
        x /= 10;
    }
    
    long long val1 = cur * x;
    long long val2 = cur * x + cur;
    
    //cout << x - val1 << " " << val2 - x << "\n";
    if(x2 - val1 < val2 - x2) cout << val1 << "\n";
    else cout << val2 << "\n";
    return 0;
}
