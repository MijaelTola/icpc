#include <bits/stdc++.h>

using namespace std;

int t, n, k;
int v[100010];

bool ver(int x) {
    long long sum = 0;
    int cur = 1;
    for (int i = x; i < n; ++i)  
        sum += v[i] / cur++;
    return sum <= k;
}

int main() {
    cin >> t;

    while(t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int a = -1, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        cout << b + 1<< "\n";
    }
    return 0;
}

