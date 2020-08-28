#include <bits/stdc++.h>

using namespace std;

int m[1010][1010];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];

    for (int i = 0; i < n; ++i)
        cout << sqrt(m[i][i]) << " ";
    cout << "\n";
    return 0;
}

