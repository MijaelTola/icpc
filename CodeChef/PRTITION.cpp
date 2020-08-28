#include <bits/stdc++.h>

using namespace std;

int v[1000010];

int main(){
    
    int t;
    scanf("%d", &t);
    while(t--) {
        int x,n;
        scanf("%d %d", &x, &n);
        long long s = (n * (n + 1)) / 2;
        s -= x;
        if(s % 2 != 0) {
            puts("impossible");
            continue;
        }
        long long a,b;
        a = b = 0;
        for (int i = n; i >= 1; i--){
            if(i == x){ 
                v[i] = 2;
                continue;
            }
            if(a >= b) v[i] = 0,b += i;
            else v[i] = 1, a += i;
        }
        if(a != b){
            puts("impossible");
            continue;
        }
        for (int i = 1; i <= n; ++i)
            printf("%d",v[i]);
        puts("");
    }
    return 0;
}

