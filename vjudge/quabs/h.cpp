#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[200010];
long long c[200010];
int b[200010];

bool f(int k) {
    memset(c, 0, sizeof c);
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i) {
        c[i % k] += max(0,v[i] - b[i % k]);
        b[i % k]++; 
    }
    

    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += c[i];
    }

    return sum >= m;
}

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    reverse(v, v + n);
    
    int a = 0, b = n;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(f(mid)) b = mid;
        else a = mid;
    }

    if(!f(b)) cout << "-1\n";
    else cout << b << "\n";
    return 0;
}

