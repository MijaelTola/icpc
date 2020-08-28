#include <bits/stdc++.h>

using namespace std;

const int n = 300000010;
bitset<n> is;

int main() {
    
    int l,r;
    scanf("%d %d", &l, &r);
    
    if(r <= 1) return puts("0"), 0;

    for (int i = 2; i < n; i += 2)
        is[i] = 1;

    for (int i = 3; i * i < n; i += 2) {
        if(is[i]) continue;
        for (int j = i * i; j < n; j += i)
            is[j] = 1;
    }

    //Fermat theorem 4 * k + 1

    int ans = 0;
    for (int i = 5; i <= n; i += 4) {
        if(l <= i and i <= r and !is[i])
            ans++;
    }

    if(l <= 2) ans++;

    printf("%d\n", ans);
    return 0;
}

