#include <bits/stdc++.h>

using namespace std;

int a[200010];

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        cout << i << " wtf\n";
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << "\n";
    return 0;
}

