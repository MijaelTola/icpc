#include <bits/stdc++.h>

using namespace std;

int n;
int c[200010];
int d[200010];
long long cur = 0;
int f(long long k) {

    int div = k >= 1900 ? 1 : 2;

    for (int i = 0; i < n; ++i) {
        if(div == d[i]) {
            k += c[i];
            div = k >= 1900 ? 1 : 2;
        } else {
            if(d[i] == 1) return 1;
            else return 0;
        }
    }
    cur = k;
    return 2;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> c[i] >> d[i];

    
    long long a = -1e10, b = 1e10 + 1;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(f(mid) >= 1) a = mid;
        else b = mid;
    }
    f(a);
    if(a >= 1e9) cout << "Infinity\n";
    else if(f(a) != 2) cout << "Impossible\n";
    else cout <<cur << "\n";
    return 0;
}

