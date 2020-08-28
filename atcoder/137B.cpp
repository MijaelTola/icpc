#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    swap(n,k);
    
    for (int i = n - k + 1; i <= n + k - 1; ++i)
        cout << i << " ";
    cout << "\n";
    return 0;
}

