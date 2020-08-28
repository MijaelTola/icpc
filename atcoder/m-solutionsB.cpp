#include <bits/stdc++.h>

using namespace std;

int main() {

    int v[3];
    
    for (int i = 0; i < 3; ++i)
        cin >> v[i];

    int k;
    cin >> k;

    int p = 1;
    while(k-- and p < 3) {
        if(v[p] <= v[p - 1]) v[p] *= 2;
        else p++, k++;
    }

    if(v[0] < v[1] and v[1] < v[2]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

