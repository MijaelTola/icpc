#include <bits/stdc++.h>

using namespace std;

int a[20];
int c[20];

int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans += x;
    }

    for (int i = 0; i < n - 1; ++i)
        cin >> c[i];


    
    for (int i = 0; i < n - 1; ++i) {
        if(a[i] + 1 == a[i + 1])
            ans += c[a[i]];
    }

    cout << ans << "\n";
    return 0;
}

