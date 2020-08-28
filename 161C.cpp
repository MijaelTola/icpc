#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n,k;
    cin >> n >> k;

    cout << min(n % k,abs((n % k) - k)) << "\n";
    return 0;
}

