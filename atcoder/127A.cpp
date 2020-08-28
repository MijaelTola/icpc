#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a,b;
    scanf("%d %d", &a, &b);

    if(a < 6) return puts("0"),0;
    if(a >= 6 and a <= 12) return printf("%d\n", b / 2),0;

    printf("%d\n", b);
    return 0;
}

