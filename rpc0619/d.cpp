#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long x,y;
    while(cin >> x >> y and x and y) {
        unsigned long long t = x + y - 1;
        unsigned long long sum (t * (t + 1) / 2LL);
        if(x % 2LL  == y % 2LL) cout << sum - (x - 1) << "\n";
        else cout << sum - (y - 1)<< "\n";
    }
    return 0;
}

