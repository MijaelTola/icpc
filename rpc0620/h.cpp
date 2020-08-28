#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int mn = 1e9;
    int id = -1;

    for (int i = 0; i < n - 2; i++) {
        if(max(v[i], v[i + 2]) < mn) {
            mn = max(v[i], v[i + 2]);
            id = i;
        }
    }
    cout << id + 1 << " " << mn << "\n";
    return 0;
}

