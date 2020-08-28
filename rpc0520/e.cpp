#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a = 0, b = 0;
    for (int i = 1; i <= 100 - n; ++i) {
        int sum = 0;
        for (int j = i; j <= i + n - 1; ++j) {
            sum += j;
        }
        if(sum & 1) a = 1;
        else b = 1;
    }

    if(a and b) cout << "Either\n";
    else if(a) cout << "Odd\n";
    else cout << "Even\n";

    return 0;
}

