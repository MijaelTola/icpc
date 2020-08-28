#include <bits/stdc++.h>

using namespace std;

int main() {

    long long a,b,k;
    cin >> a >> b >> k;

    long long mn = min(a,k);
    a -= mn;
    k -= mn;

    mn = min(b,k);
    b -= mn;
    k -= mn;
    cout << a << " " << b << "\n";
    return 0;
}

