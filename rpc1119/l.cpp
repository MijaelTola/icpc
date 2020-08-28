#include <bits/stdc++.h>

using namespace std;

int main() {


    long long n,l;

    cin >> l >> n;

    long long ans = 1;
    long long sum = 0;

    while(n > 0 and l % n != 0) {
        sum = l % n;
        n = n - sum;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

