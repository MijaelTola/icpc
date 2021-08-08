#include <bits/stdc++.h>

using namespace std;

int main() {
    auto lcm = [&](long long a, long long b) {
        return (a * b) / __gcd(a,b);
    };


    int t;
    cin >> t;

    while(t--) {
        long long n,s,k;
        cin >> n >> s >> k;


        cout << lcm((n + s) % n, k) << endl;



    }
    return 0;
}

