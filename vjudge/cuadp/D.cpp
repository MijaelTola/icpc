#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n;
    cin >> n;

    if(n & 1) {
        cout << "0\n";
    } else {
        cout << (1LL << (n / 2)) << "\n";
    }
    return 0;
}

