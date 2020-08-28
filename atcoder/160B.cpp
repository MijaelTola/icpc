#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long x;
    cin >> x;

    long long a = x / 500;
    x %= 500;
    long long b = x / 5;

    cout << a * 1000 + b * 5 << "\n";
    return 0;
}

