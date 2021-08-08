#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,x;
    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
        int y;
        cin >> y;
        if(i & 1) x -= y;
        else x -= (y - 1);
    }

    if(x >= 0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

