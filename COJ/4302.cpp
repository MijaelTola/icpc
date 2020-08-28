#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b) {
    return (a * b) / __gcd(a,b);
}
int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a,b));
    }
    return 0;
}

