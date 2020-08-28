#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    scanf("%d", &t);

    while(t--) {
        int n,q;
        scanf("%d %d", &n, &q);
        
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (__builtin_popcount(x) & 1) a++;
            else b++;
        }

        
        while(q--) {
            int x;
            scanf("%d", &x);
            int da = a, db = b;
            for (int i = 0; i < 30; ++i) 
                if(x & (1 << i)) swap(da, db);

            printf("%d %d\n", db, da);
        }
    }
    
    return 0;
}

