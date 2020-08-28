#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        long long total = 0;
        for (int i = 0; i < n - 1; i++) {
            int u,v,c1,c2;
            scanf("%d %d %d %d", &u, &v, &c1, &c2);
            total += c1 + c2;
        }

        int q;
        scanf("%d", &q);
        while(q--) {
            int x,y;
            scanf("%d %d", &x, &y); }
    }
    return 0;
}

