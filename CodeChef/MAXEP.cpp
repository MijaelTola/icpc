#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,c,x,i;

    scanf("%d %d", &n, &c);
    
    int pos = 1;
    
    int cnt = 0;

    while(pos <= n) {
        printf("1 %d\n", pos);
        fflush(stdout);
        scanf("%d", &x);
        if(x == 1) {
            printf("2\n");
            fflush(stdout);
            break;
        }
        pos += 500;
    }

    pos -= 500;
    for (i = max(1,pos + 1); i <= min(pos + 500, n); ++i) {
        printf("1 %d\n", i);
        fflush(stdout);
        cnt++;
        scanf("%d", &x);
        if(x == 1) break;
    }

    printf("3 %d\n", i);
    fflush(stdout);
    return 0;
}

