#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int v[3];
    cin >> v[0] >> v[1] >> v[2];

    swap(v[0], v[1]);
    swap(v[0], v[2]);

    for (int i = 0; i < 3; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}

