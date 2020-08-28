#include <bits/stdc++.h>

using namespace std;

long long a[10][10];
int main() {
    
    int n;
    cin >> n;

    
    for (int i = 1; i <= n; ++i) {
        int last = i % 10;  
        int first = i;
        while(first / 10 > 0) first /= 10;
        a[first][last]++;
    }
    
    long long ans = 0;
    for (int i = 1; i <= 9; ++i) {
       for (int j = 1; j <= 9; ++j)
           ans += a[i][j] * a[j][i];
    }
    cout << ans << "\n";
    return 0;
}

