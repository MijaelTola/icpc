#include <bits/stdc++.h>

using namespace std;

int main() {
    long long r,d,x;
    scanf("%lld %lld %lld", &r, &d, &x);

    for (int i = 0; i < 10; ++i) {
        x = x * r - d;
        printf("%lld\n", x);
    }
    return 0;
}

