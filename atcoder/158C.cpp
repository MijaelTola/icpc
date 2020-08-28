#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 1; i < 100000; ++i) {
        int da = i * 0.08;
        int db = i * 0.1;
        if(da == n and db == m) return cout << i << "\n", 0 ;
    }
    cout << "-1\n";
    return 0;
}

