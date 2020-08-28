#include <bits/stdc++.h>

using namespace std;

long long get(long long x) {
    return x * (x + 1) / 2;
}
int main() {
    
    int k,n;
    cin >> k >> n;

    while(n--) {
        int x;
        cin >> x;

        int a = 0, b = 1e9 + 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(mid <= k) {
                a = mid;
                continue;
            }
            int l = get(mid);
            int r = k - get(mid) - get(x - 1);
            if(l < r) a = mid;
            else b = mid;
        }
    }
    return 0;
}

