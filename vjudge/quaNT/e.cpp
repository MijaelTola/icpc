#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int mx = 0;
    auto factors = [&] (int x) {
        set<int> v;
        long long ans = 1;
        for (int i = 2; i <= x; ++i) {
            int cnt = 0;
            while(x % i == 0) {
                cnt++;
                x /= i;
            }
            if(cnt) {
                mx = max(mx, cnt);
                ans *= i;
                v.insert(cnt);
            }
        }
        return make_pair(v.size() != 1, ans);
    };


    auto p = factors(n);

    
    long long p2 = 1;

    while(p2 < mx) p2 <<= 1;
    bool check = (p2 != mx) or p.first;
    if(n == 1) check = 0;
    printf("%d %d\n", (int)p.second, (int)log2(p2) + check);

    return 0;
}

