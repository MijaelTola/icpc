#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b,c,k;
    cin >> a >> b >> c >> k;

    int da = min(a, k);
    k -= da;
    int db = min(b, k);
    k -= db;
    int dc = min(c, k);
    k -= dc;

    cout <<da - dc << "\n";
    return 0;
}

