#include <bits/stdc++.h>

using namespace std;

int v[50];
int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    sort(v, v + n);
    
    long double ans = v[0];
    for (int i = 1; i < n; ++i) {
        ans += v[i];
        ans /= 2.;
    }

    printf("%.10Lf\n", ans);
    return 0;
}

