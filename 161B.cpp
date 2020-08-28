#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int m,n;
    cin >> n >> m;
    vector<double> v(n);
    
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    double cur = sum / (4 * m);
    
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        cnt += v[i] >= cur;
    }

    if(cnt >= m) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

