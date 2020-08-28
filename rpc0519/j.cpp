#include <bits/stdc++.h>

using namespace std;

long long m,cur;
long long get(long long x) {
    return (x * (x + 1)) / 2;
}

int f(int r) {
    int a = m - 1, b = r;
    while(b - a > 1) {
        long long mid = (a + b) / 2;
        long long vl = get(mid - 1) - cur;
        long long vr = get(r) - get(mid);
        if(vl >= vr) b = mid;
        else a = mid;
    }
    long long vl = get(b - 1) - cur;
    long long vr = get(r) - get(b);
    if(vl == vr) return b;
    return -1;
}

int main() {
    cin >> m;
    cur = get(m - 1);
    for (int i = m + 1; i <= 10000000; ++i) {
        int ans = f(i);
        if(ans != -1) return cout << m << " " << ans << " " << i << "\n",0;
    }

    return 0;
}

