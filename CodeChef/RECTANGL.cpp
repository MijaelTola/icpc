#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d,t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a == c and b == d) puts("YES");
        else if(b == c and a == d) puts("YES");
        else if(a == b and c == d) puts("YES");
        else puts("NO");
    }
    return 0;
}

