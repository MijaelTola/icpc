#include <bits/stdc++.h>

using namespace std;

int n,m,c;
int v[100010];
int a[100010];
int b[100010];
int d[100010];

int main() {
    
    scanf("%d %d %d", &n, &m, &c);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    for (int i = 0; i < m; ++i) {
        scanf("%d", a + i);
        b[i] = d[i] = a[i];
    }

    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
        b[i] %= c;
    }
    for (int i = n; i >= 0; i--) {
        d[i] += d[i + 1];
        d[i] %= c;
    }


    int i,j,p;
    for (i = 0, j = n - 1, p = m - 1; i <= n - m and i <= j and p >= 0; ++i, j--, p--) {
        v[i] += b[i];
        v[i] %= c;
        v[j] += d[p];
        v[j] %= c;
    }
    
    for (int l = i, cur = 0; l <= j; ++l, cur++) {
        int total = (b[l] - b[cur] + c) % c;
        if(i >= m) total = d[0];
        v[l] += total;
        v[l] %= c;
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    puts("");

    return 0;
}

