#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    scanf("%d %d", &n, &k);

    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        g = __gcd(g,x);
    }

    set<long long> ans;
    for (long long i = 0, j = 0; i < k; i++, j += g) {
        ans.insert(j % k);
    }

    printf("%d\n", (int)ans.size());
    for (auto x: ans)
        printf("%lld ", x);
    puts("");
        
    return 0;
}

