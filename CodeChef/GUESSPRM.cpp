#include <bits/stdc++.h>

using namespace std;


int main() {
    
    int t,x;
    char s[3];
    scanf("%d", &t);
    while(t--) {
        printf("1 %d\n", (int)1e9);   
        fflush(stdout);
        scanf("%d", &x);
        printf("1 %d\n", (int)1e9 - x - 1);
        fflush(stdout);
        scanf("%d", &x);
        printf("2 %d\n", x + 1);
        fflush(stdout);
        scanf("%s", s);
        if(strcmp(s, "Yes") != 0)break;
    }
    return 0;
}

