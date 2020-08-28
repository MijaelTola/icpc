#include <bits/stdc++.h>

using namespace std;

int v[4];

int main() {

    for (int i = 0; i < 4; ++i)
        cin >> v[i];

    sort(v, v + 4);
    
    for (int i = 0; i < 3; ++i) {
        cout << v[3] - v[i] << " ";
    }
    cout << "\n";
    return 0;
}

