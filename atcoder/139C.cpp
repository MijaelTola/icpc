#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];


    int last = -1;
    int c = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(v[i] >= last) c++;
        else c = 1;
        ans = max(ans, c - 1);
        last = v[i];
    }

    cout << ans << "\n";
    return 0;
}

