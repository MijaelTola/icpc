#include <bits/stdc++.h>

using namespace std;

//6 9 4 1
int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m,x,y;
        scanf("%d%d%d%d",&n, &m, &x, &y);
        n--,m--;
        if(n % x == 0 and m % y == 0) 
            puts("Chefirnemo");
        else if(n - 1 >= 0 and m - 1 >= 0 
                and (n - 1) % x == 0 and (m - 1) % y == 0)
            puts("Chefirnemo");
        else puts("Pofik");
    }
    return 0;
}

