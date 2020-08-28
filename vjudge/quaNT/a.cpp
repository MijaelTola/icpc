#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(__gcd(a,b) != 1) puts("Infinite");
        else puts("Finite");
    }
    return 0;
}

