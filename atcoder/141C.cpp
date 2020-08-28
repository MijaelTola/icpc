#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int n,k,q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i)
        v[i] = k - q;
    while(q--) {
        int x;
        cin >> x;
        v[x]++;
    }
    
    for (int i = 1; i <= n; ++i)
        puts(v[i] > 0 ? "Yes": "No");

    return 0;
}

