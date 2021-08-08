#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x;
    cin >> x;

    int ans = 1;
    x++;

    while(x % 100 != 0) x++, ans++;

    cout << ans << "\n";
    return 0;
}

