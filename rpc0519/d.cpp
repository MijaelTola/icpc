#include <bits/stdc++.h>

using namespace std;

long long bit[210010];
int v[100010];
int n,q;

void update(int x, long long value) {
    for (; x <= n; x += x & -x) 
        bit[x] += value;
}

long long query(int x) {
    long long sum = 0;
    for(; x > 0; x -= x&-x)
        sum += bit[x];
    return sum;
}

long long f(int mid) {
    long long m = v[mid];
    long long left = query(mid);
    long long right = query(n) - left;
    left -= m;
    if(m & 1) {
        if(left <= right) left++;
        else right++;
    }
    return abs(left - right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        v[i] = x;
        update(i, x);
    }

    while(q--) {
        int x,y;
        cin >> x >> y;
        x++;
        long long dif = y - v[x];
        v[x] = y;
        update(x, dif);
        int a = 0, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(f(mid) <= f(mid + 1)) b = mid;
            else a = mid;
        }
        cout << b - 1 << "\n";
    }

    return 0;
}

