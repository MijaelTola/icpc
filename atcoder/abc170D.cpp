#include <bits/stdc++.h>

using namespace std;

int v[2000010];
int c[2000010];

int main() {
    
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }

    long long ans = 0;
    for (int i = 1; i < 2000010; ++i) {
        if(v[i] == 0) continue;
        for (int j = i + i; j < 2000010; j += i) 
            c[j]++;
    }
    
    for (int i = 1; i < 2000010; ++i) {
        if(c[i] == 0 and v[i] == 1) 
            ans++;
    }

    
    cout << ans << "\n";

    return 0;
}

