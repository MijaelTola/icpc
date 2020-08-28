#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    int sum = 0; 

    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        sum += y;
    }
    sum = abs(sum);
    int ans = sum / x;
    if(sum % x != 0) ans++;
    cout << ans << "\n";

    
    return 0;
}

