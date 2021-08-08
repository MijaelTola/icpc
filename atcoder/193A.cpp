#include <bits/stdc++.h>

using namespace std;

int main() {
    
    double a,b;
    cin >> a >> b;

    cout.precision(10);
    cout << fixed << (1 - b / a) * 100 << "\n";
    return 0;
}

