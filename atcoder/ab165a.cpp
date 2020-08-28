#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,a,b;
    cin >> n >> a >> b;
    
    int d = n;
    while(n < a) n += d;

    cout << (a <= n and n <= b ? "OK" : "NG") << "\n";
    return 0;
}

