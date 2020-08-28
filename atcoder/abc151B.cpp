#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k,m;
    cin >> n >> k >> m;
    
    int s = 0;

    for (int i = 0; i < n - 1; ++i) {
        int x;
        cin >> x;
        s += x;
    }

    for (int i = 0; i <= k; ++i) {
        int val = (s + i) / n ;
        if(val >= m) return cout << i << "\n",0;
    }
    cout <<"-1\n";
    return 0;
}

