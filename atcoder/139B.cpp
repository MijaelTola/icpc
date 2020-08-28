#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;

    cin >> n >> m;
    if(m == 1) return cout << "0\n",0;
    int cur = n;
    int ans = 1;
    while(cur < m) {
        cur--;
        cur+= n;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

